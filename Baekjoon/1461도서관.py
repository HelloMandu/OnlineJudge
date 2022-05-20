import heapq

n, m = map(int, input().split())
books = sorted(list(map(int, input().split())))

plusQueue = []
minusQueue = []

for i in books:
    if i > 0:
        heapq.heappush(plusQueue, -i)
    else:
        heapq.heappush(minusQueue, i)


arr = []
while plusQueue:
    arr.append(-heapq.heappop(plusQueue))
    for _ in range(m - 1):
        if not plusQueue:
            break
        heapq.heappop(plusQueue)

while minusQueue:
    arr.append(-heapq.heappop(minusQueue))
    for _ in range(m - 1):
        if not minusQueue:
            break
        heapq.heappop(minusQueue)

arr.sort()
print((sum(arr) * 2) - arr[-1])
