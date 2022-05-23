import sys
input = sys.stdin.readline

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def isRange(y, x):
    return y >= 0 and y < n and x >= 0 and x < m

def bfs():
    cnt = 0
    queue = set()
    queue.add((0, 0, arr[0][0]))

    while queue:
        y, x, str = queue.pop()
        cnt = max(cnt, len(str))
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if isRange(ny, nx) and arr[ny][nx] not in str:
                queue.add((ny, nx, str + arr[ny][nx]))

    return cnt

n, m = map(int, input().split())
arr = [list(input()) for _ in range(n)]
result = 0
print(bfs())