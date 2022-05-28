arr = list(map(int, input().split()))
setArr = set(arr)
if len(setArr) == 1:
    print(10000 + (arr.pop() * 1000))
elif len(setArr) == 2:
    print(1000 + (sorted(arr)[1] * 100))
else:
    print(max(arr) * 100)

