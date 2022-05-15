import sys
input = sys.stdin.readline

def isRange(y, x, len):
    return r >= y and r < y + len and c >= x and c < x + len

def isValid(y, x):
    return y == r and x == c

def solve(y, x, len):
    global result
    if len <= 2:
        if isValid(y, x):
            print(result)
            return
        result += 1
        if isValid(y, x + 1):
            print(result)
            return
        result += 1
        if isValid(y + 1, x):
            print(result)
            return
        result += 1
        if isValid(y + 1, x + 1):
            print(result)
            return
        result += 1
        return

    if(isRange(y, x, len)):
        solve(y, x, len / 2)
    else:
        result += int(len / 2 * len / 2)
    if(isRange(y, x + len / 2, len)):
        solve(y, x + len / 2, len / 2)
    else:
        result += int(len / 2 * len / 2)
    if(isRange(y + len / 2, x, len)):
        solve(y + len / 2, x, len / 2)
    else:
        result += int(len / 2 * len / 2)
    if(isRange(y + len / 2, x + len / 2, len)):
        solve(y + len / 2, x + len / 2, len / 2)
    else:
        result += int(len / 2 * len / 2)


result = 0
n, r, c = map(int, input().split())
solve(0, 0, 2 ** n)