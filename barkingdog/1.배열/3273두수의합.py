n = int(input())
arr = list(map(int, input().split()))
x = int(input())
dic = set()

ret = 0
for i in arr:
    if x - i in dic:
        ret += 1
    dic.add(i)
print(ret)
