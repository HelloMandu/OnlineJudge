m = 10
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

def isRange(y, x):
    return 0 <= y < n and 0 <= x < m

def dfs(y, x):
    visited[y][x] = True
    ret = 1
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if isRange(ny, nx) and not visited[ny][nx] and arr[ny][nx] == arr[y][x]:
            ret += dfs(ny, nx)
    return ret

def removeDfs(y, x, key):
    visited2[y][x] = True
    arr[y][x] = '0'
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if isRange(ny, nx) and not visited2[ny][nx] and arr[ny][nx] == key:
            removeDfs(ny, nx, key)

def down():
    for x in range(m - 1, -1, -1):
        queue = []
        for y in range(n - 1, -1, -1):
            if arr[y][x] != '0':
                queue.append(arr[y][x])
            arr[y][x] = '0'
        for y in range(n - 1, -1, -1):
            if not queue:
                break
            arr[y][x] = queue.pop(0)

n, k = map(int, input().split())
arr = [list(input()) for _ in range(n)]

while True:
    visited = [[False] * m for _ in range(n)]
    visited2 = [[False] * m for _ in range(n)]
    existed = False
    for i in range(n):
        for j in range(m):
            if arr[i][j] == '0' or visited[i][j]:
                continue
            cnt = dfs(i, j)
            if cnt >= k:
                removeDfs(i, j, arr[i][j])
                existed = True
    if not existed:
        break
    down()

for cur in arr:
    print(''.join(cur))
