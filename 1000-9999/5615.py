'''
5615번
아파트 임대
'''

import sys
input=sys.stdin.readline

def modPow(a, n, l):
    if n==0: return 1
    res=modPow(a*a%l, n//2, l)
    if n&1: res=res*a%l
    return res

def mr(n, a):
    if a%n==0: return True
    d=n-1
    while True:
        p=modPow(a, d, n)
        if p==n-1: return True
        if d%2: return (p==1 or p==n-1)
        d//=2

def isPrime(n):
    if n<=3: return False

    base=[2, 7, 61]
    for a in base:
        if not mr(n, a): return False
    return True

t=int(input())

ans=0
for _ in range(t):
    n=int(input())
    if isPrime(2*n+1): ans+=1

print(ans)