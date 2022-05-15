n = int(input())
arrN = list(map(int, input().split()))
m = int(input())
arrM = list(map(int, input().split()))

map = {}
for i in arrN:
    map[i] = True

for i in arrM:
    print(1 if i in map else 0)