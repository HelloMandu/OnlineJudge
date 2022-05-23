from itertools import combinations

t = ['a', 'e', 'i', 'o', 'u']

n, c = map(int, input().split())
arr = sorted(map(str, input().split()))
arr.sort()

for str in combinations(arr, n):
    cnt = 0
    for i in str:
        if i in t:
            cnt += 1
    if cnt >= 1 and cnt <= n - 2:
        print(''.join(str))

