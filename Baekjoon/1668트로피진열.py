n = int(input())

arr = []
for _ in range(n):
    arr.append(int(input()))

maxHeight = 0
result = 0
for i in arr:
    if i > maxHeight:
        maxHeight = i
        result += 1
print(result)

maxHeight = 0
result = 0
for i in reversed(arr):
    if i > maxHeight:
        maxHeight = i
        result += 1
print(result)
