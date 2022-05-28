
n = int(input())

result = 0
while n:
    n -= 1
    arr = sorted(list(map(int, input().split())))
    setArr = set(arr)
    if len(setArr) == 1:
        result = max(result, 50000 + (arr.pop() * 5000))
    elif len(setArr) == 2:
        if arr[1] == arr[2]:
            result = max(result, 10000 + arr[1] * 1000)
        else:
            result = max(result, 2000 + arr[1] * 500 + arr[2] * 500)
    elif len(setArr) == 3:
        for i in setArr:
            arr.remove(i)
        result = max(result, 1000 + arr[0] * 100)
    else:
        result = max(result, max(arr) * 100)

print(result)
