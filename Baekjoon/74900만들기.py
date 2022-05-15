t = int(input())

def isZero(str):
    replaced = str.replace(" ", "")
    return eval(replaced) == 0

def solve(acc, cur):
    acc += str(cur)
    if cur == n:
        if isZero(acc):
            print(acc)
        return
    solve(acc + ' ', cur + 1)
    solve(acc + '+', cur + 1)
    solve(acc + '-', cur + 1)


while t:
    t -= 1

    n = int(input())
    solve('', 1)
    print()