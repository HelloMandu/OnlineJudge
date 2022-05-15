n = int(input())

cur = 0
index = 0

while n:
    if n <= cur:
        cur = 1
    else:
        cur += 1
    n -= cur
    index += 1
print(index)