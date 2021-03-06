'''
13997번
이항 계수와 쿼리
'''

import sys
input=sys.stdin.readline

fac=[1, 1]; mod=1000000007
for i in range(2, 4000001):
    fac.append((fac[-1]*i)%mod)

def modPow(a, n, p):
    if n==0: return 1
    res=modPow(a*a%p, n//2, p)
    if n&1: res=res*a%p
    return res

m=int(input())
for _ in range(m):
    n, k=map(int, input().split())
    print(fac[n]*modPow(fac[k]*fac[n-k], mod-2, mod)%mod)