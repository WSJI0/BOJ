'''
1111번
IQ Test
'''

import sys

n=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split()))

A=0
B=0
ans=''

if n==1:
    print("A")
elif n==2:
    if a[0]==a[1]:
        print(a[0])
    else:
        print("A")
else:
    for i in range(n-1):
        if i==0:
            if a[0]==a[1]:
                A=1
                B=0
            else:
                A=(a[2]-a[1])//(a[1]-a[0])
                B=a[1]-(a[0]*A)
        else:
            if a[i]*A+B!=a[i+1]:
                ans='B'
    if ans!='B':
        print(a[-1]*A+B)
    else:
        print(ans)