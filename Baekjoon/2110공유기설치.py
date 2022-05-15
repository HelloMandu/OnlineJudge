import sys

input = sys.stdin.readline

n, c = map(int, input().split())
arr = sorted([int(input()) for _ in range(n)])

result = 0
left = 0
right = arr[-1] - arr[0]

while left <= right:
    mid = (left + right) // 2
    count = 1
    wifi = arr[0]
    for i in range(1, n):
        if arr[i] - wifi >= mid:
            count += 1
            wifi = arr[i]

    if count >= c:
        left = mid + 1
        result = mid
    else:
        right = mid - 1

print(result)


