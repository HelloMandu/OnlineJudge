n = int(input())
k = int(input())
coord = sorted(list(map(int, input().split())))

if k >= n:
    print(0)
    exit()
diff = []
for i in range(1, n):
    diff.append(coord[i] - coord[i - 1])
diff.sort()
for _ in range(k - 1):
    diff.pop()

print(sum(diff))
