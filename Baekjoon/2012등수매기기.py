n = int(input())

arr = []
for _ in range(n):
    i = int(input())
    arr.append(i)

arr.sort()

result = 0
for i in range(1, n + 1):
    result += abs(arr[i - 1] - i)
print(result)


