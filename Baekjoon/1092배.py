n = int(input())
arr = sorted(list(map(int, input().split())), reverse=True)
m = int(input())
crains = sorted(list(map(int, input().split())), reverse=True)

if crains[0] > arr[0]:
    print(-1)
    exit()

cnt = 0
while crains:
    for i in arr:
        if not crains:
            break
        for j in crains:
            if i >= j:
                crains.remove(j)
                break
    cnt += 1
print(cnt)
