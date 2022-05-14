import heapq
import sys

input = sys.stdin.readline
INF = int(1e9)

def dijkstra(graph, start):
    distance = [INF] * len(graph)
    distance[start] = 0
    queue = []
    heapq.heappush(queue, (0, start))

    while queue:
        cost, node = heapq.heappop(queue)
        if distance[node] < cost:
            continue
        for nextCost, nextNode in graph[node]:
            if cost + nextCost < distance[nextNode]:
                distance[nextNode] = cost + nextCost
                heapq.heappush(queue, (distance[nextNode], nextNode))

    return distance


n, m = map(int, input().split())
start = int(input())

graph = [[] for _ in range(n + 1)]

for _ in range(m):
    v, e, w = map(int, input().split())
    graph[v].append((w, e))

for i in dijkstra(graph, start)[1:]:
    if i != INF:
        print(i)
    else:
        print('INF')