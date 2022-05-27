import heapq
import sys
input = sys.stdin.readline

INF = 10 ** 9

def dijkstra():
    heap = [(start, 0)]
    distances[start] = 0
    while heap:
        cur, dis = heapq.heappop(heap)
        if dis > distances[cur]:
            continue
        for next, cost in graph[cur]:
            if distances[next] >= distances[cur] + cost and not paths[cur][next]:
                distances[next] = distances[cur] + cost
                heapq.heappush(heap, (next, distances[next]))
    return distances[end]

def findPath():
    queue = [end]
    while queue:
        cur = queue.pop(0)
        if cur == start:
            return
        for next, cost in rGraph[cur]:
            if distances[cur] - cost == distances[next]:
                paths[next][cur] = True
                queue.append(next)


while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    start, end = map(int, input().split())
    graph = [[] for _ in range(n)]
    rGraph = [[] for _ in range(n)]
    paths = [[False] * n for _ in range(n)]
    distances = [INF] * n
    for _ in range(m):
        v, e, w = map(int, input().split())
        graph[v].append((e, w))
        rGraph[e].append((v, w))
    dijkstra()
    findPath()
    distances = [INF] * n
    result = dijkstra()
    print(result if result != INF else -1)