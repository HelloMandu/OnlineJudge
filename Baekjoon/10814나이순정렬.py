n = int(input())

arr = []
for _ in range(n):
    first, second = input().split()
    arr.append((int(first), second))

result = sorted(arr, key=lambda x: x[0])

for first, second in result:
    print(first, second)
