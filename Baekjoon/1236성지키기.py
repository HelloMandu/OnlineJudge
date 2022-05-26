n, m = map(int, input().split())

arr = []
for _ in range(n):
    arr.append(list(input()))

rowCount = 0
for i in range(n):
    flag = False
    for j in range(m):
        if arr[i][j] == 'X':
            flag = True
            break
    if not flag:
        rowCount += 1

colCount = 0
for i in range(m):
    flag = False
    for j in range(n):
        if arr[j][i] == 'X':
            flag = True
            break
    if not flag:
        colCount += 1

print(max(rowCount, colCount))