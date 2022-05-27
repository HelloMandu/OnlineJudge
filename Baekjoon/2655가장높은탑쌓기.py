n = int(input())

dp = [0] * n
cnt = [0] * n
arr = []
for i in range(n):
    w, h, k = map(int, input().split())
    arr.append((i + 1, w, h, k))
arr.sort(key=lambda x: x[1], reverse=True)

for i in range(n):
    dp[i] = arr[i][2]
    cnt[i] = 1
    for j in range(i):
        if arr[i][3] > arr[j][3]:
            continue
        if dp[i] < dp[j] + arr[i][2]:
            dp[i] = dp[j] + arr[i][2]
            cnt[i] = cnt[j] + 1

maxIndex = 0
for i in range(n):
    if dp[i] > dp[maxIndex]:
        maxIndex = i

print(cnt[maxIndex])
curHeight = dp[maxIndex]
for i in range(maxIndex, -1, -1):
    if curHeight == dp[i]:
        print(arr[i][0])
        curHeight -= arr[i][2]

