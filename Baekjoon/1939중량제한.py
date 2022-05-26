import sys
input = sys.stdin.readline

def bfs(weight):
    queue = [start]
    visited = [False] * (n + 1)
    visited[start] = True
    while queue:
        front = queue.pop(0)
        for next, nextWeight in graph[front]:
            if not visited[next] and nextWeight >= weight:
                visited[next] = True
                queue.append(next)
    return visited[end]

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
left = 10 ** 9
right = 0
for _ in range(m):
    v, e, w = map(int, input().split())
    graph[v].append((e, w))
    graph[e].append((v, w))
    left = min(left, w)
    right = max(right, w)

start, end = map(int, input().split())

result = left
while left <= right:
    mid = (left + right) // 2
    if bfs(mid):
        left = mid + 1
        result = mid
    else:
        right = mid - 1
print(result)