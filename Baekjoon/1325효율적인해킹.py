import sys
from collections import deque
input = sys.stdin.readline

def bfs(start):
    queue = deque([start])
    visited = [False] * (n+1)
    visited[start] = True
    ret = 0
    while queue:
        cur = queue.popleft()
        ret += 1
        for i in graph[cur]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True
    return ret

n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]
for _ in range(m):
    v, e = map(int, input().split())
    graph[e].append(v)

connected = [0] * (n+1)
maxResult = 0
for i in range(1, n+1):
    connected[i] = bfs(i)
    maxResult = max(maxResult, connected[i])

results = []
for i in range(1, n + 1):
    if connected[i] == maxResult:
        results.append(i)

print(*results)