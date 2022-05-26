n, m = map(int, input().split())
arr = sorted([int(input()) for _ in range(n)])

left = 0
right = arr[-1] - arr[0]
result = 0
while left <= right:
    mid = (left + right) // 2
    cnt = 1
    wifi = arr[0]
    for i in range(1, n):
        if wifi + mid <= arr[i]:
            cnt += 1
            wifi = arr[i]
    if cnt >= m:
        left = mid + 1
        result = mid
    else:
        right = mid - 1
print(result)
