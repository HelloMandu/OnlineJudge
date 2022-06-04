from copy import deepcopy
INF = 10 ** 9

def solution(start, end):
    if dp[start][end] != INF:
        return dp[start][end]
    elif start == end:
        dp[start][end] = 0
        return 0
    elif start + 1 == end:
        dp[start][end] = arr[start] + arr[end]
        return dp[start][end]

    for mid in range(start, end):
        dp[start][end] = min(dp[start][end], solution(start, mid) + solution(mid + 1, end))

    dp[start][end] += prefixSum[end] - prefixSum[start - 1]
    return dp[start][end]

t = int(input())
while t:
    t -= 1
    n = int(input())
    arr = [0] + list(map(int, input().split()))
    prefixSum = deepcopy(arr)
    for i in range(1, n + 1):
        prefixSum[i] += prefixSum[i - 1]
    dp = [[INF] * (n + 1) for _ in range(n + 1)]
    print(solution(1, n))