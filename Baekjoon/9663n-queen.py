def promising(r):
    for i in range(r):
        if r - i == abs(arr[r] - arr[i]):
            return False
    return True

def solve(r):
    if r == n:
        global result
        result += 1
        return

    for i in range(n):
        if visit[i]:
            continue
        arr[r] = i
        if promising(r):
            visit[i] = True
            solve(r + 1)
            visit[i] = False



n = int(input())
arr = [0] * n
visit = [False] * n
result = 0
solve(0)
print(result)
