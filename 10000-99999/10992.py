'''
10992번
별 찍기 - 17
'''

n=int(input())

print(" "*(n-1)+"*")

if n>1:
    for i in range(2,n+1):
        if i==n:
            print("*"*(i*2-1))
        else:
            print(" "*(n-i)+"*"+" "*((i-1)*2-1)+"*")