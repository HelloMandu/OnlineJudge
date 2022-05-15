n = int(input())
tree = {}
arr = [[] for _ in range(n + 1)]
hasParent = [False] * (n + 1)
levelMin = [n] * (n + 1)
levelMax = [0] * (n + 1)
for _ in range(n):
    root, left, right = map(int, input().split())
    tree[root] = [left, right]
    if left != -1:
        hasParent[left] = True
    if right != -1:
        hasParent[right] = True

col = 0
def solve(root, depth):
    global col
    left, right = tree[root]
    if left == -1 and right == -1:
        arr[depth].append([col, root])
        levelMin[depth] = min(levelMin[depth], col)
        levelMax[depth] = max(levelMax[depth], col)
        col += 1
        return

    if left != -1:
        solve(left, depth + 1)

    arr[depth].append([col, root])
    levelMin[depth] = min(levelMin[depth], col)
    levelMax[depth] = max(levelMax[depth], col)
    col += 1

    if right != -1:
        solve(right, depth + 1)

def getWidth(arr):
    left = 0
    right = 0
    for col, root in arr:
        if not left:
            left = col
            right = col
        else:
            right = col
    return right - left + 1

hasParent.pop(0)
root = 0
if len(hasParent) > 0:
    root = hasParent.index(False) + 1
solve(root, 1)

results = list(map(lambda x: x[1] - x[0] + 1, zip(levelMin, levelMax)))
maxWidth = max(results)
print(results.index(maxWidth), maxWidth)


