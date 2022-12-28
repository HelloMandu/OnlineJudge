inp = input()

arr = [0] * 26

for i in inp:
    arr[ord(i) - ord('a')] += 1

for i in arr:
    print(i, end=' ')