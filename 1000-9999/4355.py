'''
4355번
서로소
'''

import sys
input=sys.stdin.readline

def phi(n):
    res=n
    for i in range(2, int(n**0.5)+1):
        if n%i==0:
            while n%i==0:
                n//=i
            res-=res//i
    if n>1:
        res-=res//n
    return res


while True:
    n=int(input())
    if n==0: break
    print(phi(n))