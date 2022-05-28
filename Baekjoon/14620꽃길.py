import sys
input = sys.stdin.readline

def isRange(y, x):
    return 0 <= y < n and 0 <= x < n

def isCross(a, b):
    dy = [-2, -1, 0, 1, 2, 1, 0, -1]
    dx = [0, 1, 2, 1, 0, -1, -2, -1]
    dy2 = [-1, 0, 1, 0]
    dx2 = [0, 1, 0, -1]
    y, x = a
    ny, nx = b
    if y == ny and x == nx:
        return True
    for i in range(8):
        nY = y + dy[i]
        nX = x + dx[i]
        if not isRange(nY, nX):
            continue
        if nY == ny and nX == nx:
            return True
    for i in range(4):
        nY = y + dy2[i]
        nX = x + dx2[i]
        if not isRange(nY, nX):
            continue
        if nY == ny and nX == nx:
            return True
    return False

def getCost(coord):
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]
    y, x = coord
    result = arr[y][x]
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        result += arr[ny][nx]
    return result

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

coord = []
for i in range(1, n - 1):
    for j in range(1, n - 1):
        coord.append((i, j))

result = 10**9
for i in coord:
    for j in coord:
        for k in coord:
            if isCross(i, j) or isCross(i, k) or isCross(j, k):
                continue
            result = min(result, getCost(i) + getCost(j) + getCost(k))

print(result)