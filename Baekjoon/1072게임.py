def getPercent(n):
    gameCnt = x + n
    winCnt = y + n
    return winCnt * 100 // gameCnt

x, y = map(int, input().split())
z = y * 100 // x

result = -1

left = 1
right = 1000000000

if x == y:
    print(-1)
    exit(0)

while left <= right:
    mid = (left + right) // 2
    percent = getPercent(mid)
    if percent > z:
        result = mid
        right = mid - 1
    else:
        left = mid + 1

print(result)
