import sys
from collections import deque

input = sys.stdin.readline

def bfs(want):
    queue = deque([start])
    visited = [False] * (n + 1)
    visited[start] = True
    while queue:
        node = queue.popleft()
        for nextNode, nextWeight in graph[node]:
            if not visited[nextNode] and nextWeight >= want:
                visited[nextNode] = True
                queue.append(nextNode)
    return visited[end]

n, m = map(int, input().split())
left = 1000000000
right = 0

graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph[b].append([a, c])
    left = min(left, c)
    right = max(right, c)

start, end = map(int, input().split())

result = left
while left <= right:
    mid = (left + right) // 2
    if bfs(mid):
        result = mid
        left = mid + 1
    else:
        right = mid - 1
print(result)
