document = input()
str = input()

index = 0
result = 0

while index <= len(document) - len(str):
    if document[index: index + len(str)] == str:
        result += 1
        index += len(str)
    else:
        index += 1

print(result)