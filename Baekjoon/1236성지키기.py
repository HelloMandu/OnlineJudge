n, m = map(int, input().split())

arr = [] * n
for i in range(n):
    arr.append(list(input()))

rowlen = n
collen = m

for i in range(n):
    flag = False
    for j in range(m):
        if arr[i][j] == 'x':
            flag = True
            break
    if flag:
        rowlen -= 1

for i in range(m):
    flag = False
    for j in range(n):
        if arr[j][i] == 'x':
            flag = True
            break
    if flag:
        collen -= 1
print(max([rowlen, collen]))
