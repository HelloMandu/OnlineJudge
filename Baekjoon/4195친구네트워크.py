from collections import defaultdict

def getParent(a):
    if not parent[a]:
        parent[a] = a
        return a
    if a == parent[a]:
        return a
    else:
        parent[a] = getParent(parent[a])
        return parent[a]

def union(a, b):
    a = getParent(a)
    b = getParent(b)
    if a == b:
        return count[a]
    parent[b] = a
    count[a] += count[b]
    return count[a]

t = int(input())

while t:
    t -= 1
    n = int(input())
    parent = defaultdict(bool)
    count = defaultdict(lambda: 1, {})
    for _ in range(n):
        a, b = input().split()
        print(union(a, b))
