from itertools import combinations

n, maxSum = map(int, input().split())

arr = sorted(list(map(int, input().split())))

result = 0
for comb in combinations(arr, 3):
    combSum = sum(comb)
    if combSum <= maxSum:
        result = max(result, combSum)

print(result)

