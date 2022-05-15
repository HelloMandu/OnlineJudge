t = int(input())

for _ in range(t):
    n, index = map(int, input().split())
    queue = [(idx, i) for idx, i in enumerate(list(map(int, input().split())))]

    cnt = 0
    while True:
        curIdx, curValue = queue[0]
        if curValue == max(queue, key=lambda x: x[1])[1]:
            cnt += 1
            queue.pop(0)
            if curIdx == index:
                break
        else:
            queue.append(queue.pop(0))
    print(cnt)
