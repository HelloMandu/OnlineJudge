def swapArr(y, x):
    for i in range(y, y + 3):
        for j in range(x, x + 3):
            arr[i][j] = '0' if arr[i][j] == '1' else '1'

n, m = map(int, input().split())
arr = [list(input()) for _ in range(n)]
arr1 = [list(input()) for _ in range(n)]

result = 0
for i in range(n - 2):
    for j in range(m - 2):
        if arr[i][j] != arr1[i][j]:
            swapArr(i, j)
            result += 1

print(result if arr == arr1 else -1)
