n = int(input())

arr = sorted(list(map(int, input().split())))

result = 0
for i in range(n):
    result += sum(arr[:i + 1])

print(result)
