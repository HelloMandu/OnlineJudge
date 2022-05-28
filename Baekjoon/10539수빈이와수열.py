n, arr = int(input()), list(map(int, input().split()))
result = [arr[0]]
for i in range(1, n):
    result.append(arr[i] * (i + 1) - sum(result))
print(*result)
