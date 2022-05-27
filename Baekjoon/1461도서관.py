n, m = map(int, input().split())
books = sorted(list(map(int, input().split())), reverse=True)

left = []
right = []
for book in books:
    if book < 0:
        left.append(-book)
    else:
        right.append(book)
left.sort(reverse=True)

result = 0
arr = []
for i in range(0, len(left), m):
    arr.append(left[i])
for i in range(0, len(right), m):
    arr.append(right[i])
arr.sort()
print(sum(arr) * 2 - arr[len(arr) - 1])

