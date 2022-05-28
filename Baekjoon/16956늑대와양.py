import sys
input = sys.stdin.readline

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def isRange(y, x):
    return 0 <= y < r and 0 <= x < c

def bfs(yS, yX):
    queue = [(yS, yX)]
    visited[yS][yX] = 1
    while queue:
        y, x = queue.pop(0)
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if not isRange(ny, nx) or visited[ny][nx]:
                continue
            if arr[ny][nx] == '.':
                visited[ny][nx] = 1
                queue.append((ny, nx))
            elif arr[ny][nx] == 'S':
                if arr[y][x] == 'W':
                    return False
                arr[y][x] = 'D'
    return True
r, c = map(int, input().split())
arr = [list(input()) for _ in range(r)]

wolf = []
visited = [[False] * c for _ in range(r)]
for i in range(r):
    for j in range(c):
        if arr[i][j] == 'W':
            wolf.append([i, j])

for yS, yX in wolf:
   if not bfs(yS, yX):
       print(0)
       exit(0)

print(1)
for row in arr:
    print(''.join(row))
