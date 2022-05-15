import heapq
import sys

input = sys.stdin.readline

n = int(input())
heap = []

for _ in range(n):
    inp = int(input())
    if inp == 0:
        print(heapq.heappop(heap) if heap else 0)
    else:
        heapq.heappush(heap, inp)
