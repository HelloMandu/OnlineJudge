from collections import defaultdict

n = int(input())
map = defaultdict(int)

for _ in range(n):
    map[input()] += 1

maxValue = max(map.values())

result = sorted(list(filter(lambda x: x[1] == maxValue, map.items())))[0]
print(result[0])

