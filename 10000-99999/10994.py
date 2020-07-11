'''
10994번
별 찍기 - 19
'''

n=int(input())

def solve(n):
    if n==1:
        print("*")
        return
    
    print("*"*(n*4-3))
    for i in range(1, n*2-2):
        print("* "*((i+1)//2), end='')
        if i%2==0:
            print("*"*((n-(i+1)//2)*4-3), end='')
        else:
            print(" "*((n-(i+1)//2)*4-3), end='')
        print(" *"*((i+1)//2))

    print("* "*(n*2-1))
    for i in range(n*2-3, 0, -1):
        print("* "*((i+1)//2), end='')
        if i%2==0:
            print("*"*((n-(i+1)//2)*4-3), end='')
        else:
            print(" "*((n-(i+1)//2)*4-3), end='')
        print(" *"*((i+1)//2))
    print("*"*(n*4-3))

solve(n)