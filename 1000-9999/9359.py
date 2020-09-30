'''
9359번
서로소

미완성
'''

import sys
input=sys.stdin.readline

def factor(n):
    res=[]
    for i in range(2, int(n**0.5)+1):
        if n%i==0:
            res.append(i)
            while n%i==0 and n!=0:
                n//=i
    return res

t=int(input())
for _ in range(t):
    a, b, n=map(int, input().split())
    print(factor(n))