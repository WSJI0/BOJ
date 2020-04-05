'''
13015번
별 찍기 - 23
'''

n=int(input())

for i in range(n-1):
    print(" "*i, end='')
    if i==0:
        print("*"*n+" "*(n*2-3)+"*"*n)
    else:
        print("*"+" "*(n-2)+"*"+" "*((n-i-1)*2-1)+"*"+" "*(n-2)+"*")

print(" "*(n-1)+"*"+" "*(n-2)+"*"+" "*(n-2)+"*")

for j in range(n-2,-1,-1):
    print(" "*j, end='')
    if j==0:
        print("*"*n+" "*(n*2-3)+"*"*n)
    else:
        print("*"+" "*(n-2)+"*"+" "*((n-j-1)*2-1)+"*"+" "*(n-2)+"*")