'''
11402번
이항 계수 4
'''

import sys
input=sys.stdin.readline

n, k, m=map(int, input().split())

fac=[1, 1]
for i in range(2, 2001):
    fac.append(fac[-1]*i%m)

a=[]; b=[]
for i in range(60, -1, -1):
    a.append(n//pow(m, i)); n=n%pow(m, i)
    b.append(k//pow(m, i)); k=k%pow(m, i)

def modPow(a, n, p):
    if n==0: return 1
    res=modPow(a*a%p, n//2, p)
    if n&1: res=res*a%p
    return res

res=1
for i in range(61):
    if a[i]==b[i]==0: continue
    if a[i]<b[i]: res=0
    else: res*=(fac[a[i]]*modPow(fac[b[i]]*fac[a[i]-b[i]], m-2, m))%m

print(res%m)