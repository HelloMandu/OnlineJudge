arr = list(map(int, input().split()))

isAscending = True
isDescending = True

for i in range(1, 8):
    if arr[i] > arr[i - 1]:
        isDescending = False
    elif arr[i] < arr[i - 1]:
        isAscending = False
    if isAscending == False and isDescending == False:
        break

if(isAscending):
    print("ascending")
elif(isDescending):
    print("descending")
else:
    print("mixed")