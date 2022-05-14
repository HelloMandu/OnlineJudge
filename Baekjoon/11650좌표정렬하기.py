n = int(input())

arr = []
for _ in range(n):
    [x, y] = input().split(' ')
    arr.append((int(x), int(y)))

arr.sort()
for cur in arr:
    print(cur[0], cur[1])
