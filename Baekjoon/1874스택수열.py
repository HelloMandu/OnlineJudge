n = int(input())

arr = []
stack = []
for i in range(n):
    arr.append(int(input()))

result = []
cur = 0
for i in range(1, n + 1):
    result.append('+')
    stack.append(i)
    while len(stack) > 0 and arr[cur] == stack[-1]:
        stack.pop()
        result.append('-')
        cur += 1

if len(stack) == 0:
    print('\n'.join(result))
else:
    print('NO')
