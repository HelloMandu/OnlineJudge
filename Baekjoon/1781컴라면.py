import heapq

n = int(input())

arr = []
for _ in range(n):
    a, b = map(int, input().split())
    arr.append((a, b))
arr.sort()

heap = []
for dead, cup in arr:
    a = dead
    heapq.heappush(heap, cup)
    if dead < len(heap):
        heapq.heappop(heap)

print(sum(heap))