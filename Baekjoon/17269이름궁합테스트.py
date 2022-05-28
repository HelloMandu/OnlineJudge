n, m = map(int, input().split())
A, B = input().split()

alpha = [3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1]

merged = ''
minLen = min(len(A), len(B))

for i in range(minLen):
    merged += A[i] + B[i]

merged += A[minLen:]
merged += B[minLen:]

numbers = [alpha[ord(i) - ord('A')] for i in merged]

for i in range(n + m - 2):
    for j in range(n + m - i - 1):
        numbers[j] = numbers[j] + numbers[j + 1]
        numbers[j] %= 10

print("{}%".format(numbers[0] * 10 + numbers[1]))
