str = input()

result = [0, 0]
result[0] = 1 if str[0] == '1' else 0
result[1] = 0 if str[0] == '1' else 1

for i in range(1, len(str)):
    if str[i] == str[i - 1]:
        continue
    if str[i] == '1':
        result[0] += 1
    else:
        result[1] += 1


print(min(result[0], result[1]))