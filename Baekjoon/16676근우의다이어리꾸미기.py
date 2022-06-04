n = int(input())
p = '1'*len(str(n))

if len(p) == 1:
    print(1)
elif n >= int(p):
    print(len(str(n)))
else:
    print(len(str(n)) - 1)

