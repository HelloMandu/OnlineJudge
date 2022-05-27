n = int(input())
k = int(input())
arr = sorted(list(map(int, input().split())))
diff = []

for i in range(1, n):
    diff.append(arr[i] - arr[i - 1])

diff.sort(reverse=True)
for _ in range(k - 1):
    if diff:
        diff.pop(0)

print(sum(diff))