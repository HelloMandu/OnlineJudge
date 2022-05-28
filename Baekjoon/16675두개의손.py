arr = input().split()
left = arr[:2]
right = arr[2:]
dict = {
    'R': 'P',
    'S': 'R',
    'P': 'S',
}
leftSet = set(left)
rightSet = set(right)

if len(leftSet) == 1 and len(rightSet) == 1:
    if dict[left[0]] in right:
        print('TK')
    elif dict[right[0]] in left:
        print('MS')
    else:
        print('?')
elif len(leftSet) == 1:
    if dict[left[0]] in right:
        print('TK')
    else:
        print('?')
elif len(rightSet) == 1:
    if dict[right[0]] in left:
        print('MS')
    else:
        print('?')
else:
    print('?')
