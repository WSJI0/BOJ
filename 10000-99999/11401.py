'''
11401번
이항 계수 3

미완성
'''

import sys
input=sys.stdin.readline

n, k=map(int, input().split())

def nCr(n, r):
    mod=1000000007
    res=1
    r=min(r, n-r)
    for i in range(n-r, n+1):
        res=(res*(i%mod))%mod
    
    return res
    
print(nCr(n, k))