n, arr = int(input()), sorted(list(map(int, input().split())))

sum = 0
for cur in arr:
    if sum + 1 < cur:
        break
    sum += cur

print(sum + 1)