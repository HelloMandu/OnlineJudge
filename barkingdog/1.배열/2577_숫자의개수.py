a, b, c = int(input()), int(input()), int(input())

mul = a * b * c
arr = [0] * 10
while mul != 0:
    arr[mul % 10] += 1
    mul //= 10

for i in arr:
    print(i)
