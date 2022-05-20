import heapq
import sys
import math
input = sys.stdin.readline

def getLength(a, b):
    x1, y1 = a
    x2, y2 = b
    return math.sqrt(((x1 - x2) ** 2 + (y1 - y2) ** 2))

def findParent(x):
    if x == parent[x]:
        return x
    return findParent(parent[x])

def union(x, y):
    x = findParent(x)
    y = findParent(y)
    if x == y:
        return False
    elif x < y:
        parent[y] = x
    else:
        parent[x] = y
    return True

n, m = map(int, input().split())
coord = []
for _ in range(n):
    x, y = map(int, input().split())
    coord.append((x, y))

arr = []
for i in range(n):
    for j in range(i + 1, n):
        arr.append((getLength(coord[i], coord[j]), i + 1, j + 1))

parent = {}
for i in range(1, n + 1):
    parent[i] = i

for _ in range(m):
    x, y = map(int, input().split())
    union(x, y)

result = 0
arr.sort(key=lambda x: x[0])
for length, x, y in arr:
    if union(x, y):
        result += length
print("%0.2f" % result)
