import heapq

def dijkstra(start, end):
    distance = [10000000] * (n + 1)
    heap = []
    distance[start] = 0
    heapq.heappush(heap, (0, start))
    while heap:
        cost, node = heapq.heappop(heap)
        if distance[node] < cost:
            continue
        for next_node, next_cost in graph[node]:
            newCost = cost + next_cost
            if distance[next_node] > newCost:
                distance[next_node] = newCost
                heapq.heappush(heap, (newCost, next_node))
    return distance[end]

n, m, x = map(int, input().split())

graph = [[] for _ in range(n+1)]
for _ in range(m):
    v, e, w = map(int, input().split())
    graph[v].append([e, w])

result = 0
for start in range(1, n+1):
    length = dijkstra(start, x) + dijkstra(x, start)
    result = max(result, length)

print(result)



