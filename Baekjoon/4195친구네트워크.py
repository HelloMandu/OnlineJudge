from collections import defaultdict

t = int(input())

def find(x):
    if x not in parent:
        parent[x] = x
        return x

    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]


def union(a, b):
    pA = find(a)
    pB = find(b)
    if pA == pB:
        return setCount[pA]

    setCount[pA] += setCount[pB]
    parent[pB] = pA
    return setCount[pA]


result = []
while t:
    t -= 1

    parent = {}
    setCount = defaultdict(lambda: 1)
    n = int(input())
    for i in range(n):
        a, b = input().split(' ')
        print(union(a, b))
