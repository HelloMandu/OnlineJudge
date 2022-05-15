t = int(input())

result = []
while t:
    t -= 1

    strStack = []
    keyStack = []

    str = list(input())
    for i in str:
        if i == '<' and strStack:
            keyStack.append(strStack.pop())
        elif i == '>' and keyStack:
            strStack.append(keyStack.pop())
        elif i == '-' and strStack:
            strStack.pop()
        else:
            strStack.append(i)

    strStack.extend(reversed(keyStack))
    result.append(''.join(strStack))


print('\n'.join(result))