a, b = input(), input()

arr = [0] * 26
arr2 = [0] * 26
for i in a:
    arr[ord(i) - ord('a')] += 1
for i in b:
    arr2[ord(i) - ord('a')] += 1

ret = 0
for i in range(26):
    if arr[i] != arr2[i]:
        ret += abs(arr[i] - arr2[i])
print(ret)
