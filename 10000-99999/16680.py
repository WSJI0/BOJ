'''
16680번
안수빈수
'''

import sys
input=sys.stdin.readline

def num(n):
    res=0
    while n:
        res+=n%10
        n//=10
    return res

t=int(input())
for _ in range(t):
    n=int(input())
    N=n; ans=-1
    while N<=10**18:
        if num(N)%2==1:
            ans=N
            break
        else: N+=N
    print(ans)