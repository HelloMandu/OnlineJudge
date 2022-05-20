n = int(input())
cranes = sorted(list(map(int, input().split())), reverse=True)
m = int(input())
boxes = sorted(list(map(int, input().split())), reverse=True)

if boxes[0] > max(cranes):
    print(-1)
    exit()

result = 0
while boxes:
    result += 1
    for crane in cranes:
        if not boxes:
            break
        for box in boxes:
            if box <= crane:
                boxes.remove(box)
                break

print(result)

