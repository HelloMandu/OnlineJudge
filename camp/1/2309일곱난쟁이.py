from itertools import combinations

arr = sorted([int(input()) for _ in range(9)])

for combination in combinations(arr, 7):
    if sum(combination) == 100:
        for n in combination:
            print(n)
        break;