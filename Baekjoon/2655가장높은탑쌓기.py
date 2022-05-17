n = int(input())
arr = []
dp = [0] * n
parent = [0] * n

for i in range(n):
    width, height, weight = map(int, input().split())
    arr.append((i, width, height, weight))

arr.sort(key=lambda x: x[1])

for i in range(n):
    dp[i] = arr[i][2]
    for j in range(i):
        pIndex, pW, pH, pWe = arr[j]
        index, w, h, we = arr[i]
        if we > pWe:
            dp[i] = max(dp[i], dp[j] + h)

maxResult = max(dp)
index = n - 1
result = []
while index >= 0:
    if dp[index] == maxResult:
        result.append(arr[index])
        maxResult -= arr[index][2]
    index -= 1
print(len(result))
[print(i[0] + 1) for i in reversed(result)]
