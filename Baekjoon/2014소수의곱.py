import heapq
from copy import deepcopy

k, n = map(int, input().split())
arr = list(map(int, input().split()))
heap = deepcopy(arr)
bucket = set()

index = 0
top = 0
while index < n:
    top = heapq.heappop(heap)
    if top in bucket:
        continue
    index += 1
    bucket.add(top)
    for i in arr:
        heapq.heappush(heap, top * i)

print(top)
