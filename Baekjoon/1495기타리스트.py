n, s, m = map(int, input().split())
arr = list(map(int, input().split()))
cache = [[False] * (m + 1) for _ in range(n + 1)]
cache[0][s] = True

for i in range(1, n + 1):
    for j in range(m + 1):
        if not cache[i - 1][j]:
            continue
        plus = j + arr[i - 1]
        minus = j - arr[i - 1]
        if minus >= 0:
            cache[i][minus] = True
        if plus <= m:
            cache[i][plus] = True

result = -1
for i in range(m, -1, -1):
    if cache[n][i]:
        result = i
        break
print(result)
