# from copy import deepcopy
# from itertools import permutations
# dy = [0, 1, 0, -1]
# dx = [1, 0, -1, 0]
#
# def rotate(arr, query):
#     r, c, s = query
#     r, c = r - 1, c - 1
#     newArr = deepcopy(arr)
#     for len in range(1, s + 1):
#         rr, cc = r - len, c - len
#         for i in range(4):
#             for j in range(len * 2):
#                 newArr[rr + dy[i]][cc + dx[i]] = arr[rr][cc]
#                 rr, cc = rr + dy[i], cc + dx[i]
#     return newArr
#
# n, m, k = map(int, input().split())
# arr = [list(map(int, input().split())) for _ in range(n)]
# queries = [tuple(map(int, input().split())) for _ in range(k)]
# result = 10 ** 9
#
# for permu in permutations(queries):
#     copiedArr = deepcopy(arr)
#     for query in permu:
#         copiedArr = rotate(copiedArr, query)
#     result = min(result, min([sum(row) for row in copiedArr]))
# print(result)


from copy import deepcopy
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

def rotate(arr, query):
    r, c, s = query
    r, c = r - 1, c - 1
    newArr = deepcopy(arr)
    for len in range(1, s + 1):
        rr, cc = r - len, c - len
        for i in range(4):
            for j in range(len * 2):
                newArr[rr + dy[i]][cc + dx[i]] = arr[rr][cc]
                rr, cc = rr + dy[i], cc + dx[i]
    return newArr

def dfs(arr, bit):
    if bit == (1 << k) - 1:
        return min([sum(row) for row in arr])
    ret = 10 ** 9
    for i in range(k):
        if bit & (1 << i):
            continue
        ret = min(ret, dfs(rotate(arr, queries[i]), bit | (1 << i)))
    return ret

n, m, k = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
queries = [tuple(map(int, input().split())) for _ in range(k)]
print(dfs(arr, 0))
