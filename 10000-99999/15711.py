'''
15711번
환상의 짝꿍
'''

import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    a, b=map(int, input().split())
    n=a+b

    if n%2==0:
        print("YES")
    else:
        n-=2
        no=False
        if n%2==0: no=True
        for i in range(3, int(n**0.5)+1, 2):
            if n%i==0:
                no=True
                break
        if no: 
            print("NO")
        else:
            print("YES")