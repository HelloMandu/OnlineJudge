n, m = map(int, input().split())
arr = [[0] * (m + 1) for _ in range(n + 1)]
result = 0
for i in range(n):
    for index, j in enumerate(list(map(int, list(input())))):
        arr[i + 1][index + 1] = j

result = 0
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if not arr[i][j]:
            continue
        arr[i][j] = min([arr[i - 1][j], arr[i][j - 1], arr[i - 1][j - 1]]) + 1
        result = max(result, arr[i][j])

print(result ** 2)
