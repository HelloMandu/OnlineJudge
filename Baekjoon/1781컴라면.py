import heapq

n = int(input())

arr = []
for _ in range(n):
    a, b = map(int, input().split())
    arr.append((a, b))
arr.sort()

heap = []
for a, b in arr:
    heapq.heappush(heap, b)
    if len(heap) > a:
        heapq.heappop(heap)

result = 0
while heap:
    result += heapq.heappop(heap)
print(result)
