from collections import deque
import heapq
import sys
input = sys.stdin.readline
INF = sys.maxsize

def dijkstra():
    queue = []
    heapq.heappush(queue, (0, start))
    distance[start] = 0
    while queue:
        dis, cur = heapq.heappop(queue)
        if distance[cur] < dis:
            continue
        for next, nextDis in graph[cur]:
            if route[cur][next]:
                continue
            cost = dis + nextDis
            if distance[next] > cost:
                distance[next] = cost
                heapq.heappush(queue, (cost, next))

def bfs():
    queue = deque()
    queue.append(end)
    while queue:
        cur = queue.popleft()
        if cur == start:
            continue
        for prev, prevDis in rGraph[cur]:
            if distance[cur] == distance[prev] + prevDis:
                route[prev][cur] = True
                queue.append(prev)

while True:
    n, m = map(int, input().split())
    if n == 0:
        break
    start, end = map(int, input().split())
    graph = [[] for _ in range(n)]
    rGraph = [[] for _ in range(n)]
    for _ in range(m):
        u, v, p = map(int, input().split())
        graph[u].append((v, p))
        rGraph[v].append((u, p))
    route = [[False] * n for _ in range(n)]
    distance = [INF] * n
    dijkstra()
    bfs()
    distance = [INF] * n
    dijkstra()
    print(distance[end] if distance[end] != INF else -1)
