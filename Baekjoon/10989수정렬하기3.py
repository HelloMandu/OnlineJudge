import sys

n = int(sys.stdin.readline())

max = 10001
arr = [0]*max
temp = {}

for _ in range(n):
    inp = int(sys.stdin.readline())
    arr[inp] += 1

for i in range(max):
    if arr[i] != 0:
        for _ in range(arr[i]):
            print(i)
