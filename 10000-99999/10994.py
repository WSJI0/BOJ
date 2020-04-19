'''
10994번
별 찍기 - 19
'''

n=int(input())

for i in range(1, n*2-1):
    if i%2==1:
        print("*"*((n-1)*4+1))
    else:
        print("* "*(i//2), end='')
        print(" "*((n-i)//2), end='')
        print(" *"*(i//2))

print("* "*(n*2-1))

for j in range(n-1):
    pass