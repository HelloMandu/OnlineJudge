import heapq

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
indegree = [0] * (n + 1)
for _ in range(m):
    v, e = map(int, input().split())
    graph[v].append(e)
    indegree[e] += 1

heap = []
for i in range(1, n + 1):
    if indegree[i] == 0:
        heapq.heappush(heap, i)

while heap:
    cur = heapq.heappop(heap)
    print(cur, end=' ')
    for i in graph[cur]:
        indegree[i] -= 1
        if indegree[i] == 0:
            heapq.heappush(heap, i)

