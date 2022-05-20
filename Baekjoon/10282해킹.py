import heapq
import sys
input = sys.stdin.readline

INF = 10 ** 10

def dijkstra(graph, n, s):
    heap = []
    heapq.heappush(heap, (c, 0))
    distance = [INF] * (n + 1)
    distance[s] = 0
    visited = [0] * (n + 1)
    visited[s] = 1

    while heap:
        cur, dis = heapq.heappop(heap)
        if distance[cur] < dis:
            continue
        for next, nextWeight in graph[cur]:
            if distance[next] > dis + nextWeight:
                distance[next] = dis + nextWeight
                visited[next] = visited[cur] + 1
                heapq.heappush(heap, (next, distance[next]))

    last = c
    cnt = 0
    for i in range(1, n + 1):
        if distance[i] != INF:
            cnt += 1
            if distance[i] > distance[last]:
                last = i

    return (cnt, distance[last])

t = int(input())

for _ in range(t):
    n, d, c = map(int, input().split())

    graph = [[] for _ in range(n+1)]
    for i in range(d):
        a, b, s = map(int, input().split())
        graph[b].append((a, s))
    print(*dijkstra(graph, n, c))

