n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
prefixSum = [[0] * (m + 1) for _ in range(n + 1)]
for i in range(n):
    for j in range(m):
        prefixSum[i + 1][j + 1] = arr[i][j]

for i in range(n + 1):
    for j in range(m):
        prefixSum[i][j + 1] += prefixSum[i][j]
for i in range(n):
    for j in range(m + 1):
        prefixSum[i + 1][j] += prefixSum[i][j]

k = int(input())
while k:
    k -= 1
    r1, c1, r2, c2 = map(int, input().split())
    print(prefixSum[r2][c2] - prefixSum[r1 - 1][c2] - prefixSum[r2][c1 - 1] + prefixSum[r1 - 1][c1 - 1])
