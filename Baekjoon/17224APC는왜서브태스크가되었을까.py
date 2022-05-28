n, l, k = map(int, input().split())
problems = []
for _ in range(n):
    a, b = map(int, input().split())
    problems.append((a, b))

easyCnt = 0
hardCnt = 0
for i in range(n):
    easy, hard = problems[i]
    if l >= hard:
        hardCnt += 1
    elif l >= easy:
        easyCnt += 1

result = 0
hardCnt = min(hardCnt, k)
result += hardCnt * 140
if hardCnt < k:
    result += min((k - hardCnt), easyCnt) * 100
print(result)


