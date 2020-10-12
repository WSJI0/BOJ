'''
15718번
돌아온 떡파이어

미완성
'''

import sys
input=sys.stdin.readline

m=100007
fac=[1, 1]
for i in range(2, 100008):
    fac.append(fac[-1]*i%m)

def modPow(a, n, p):
    if n==0: return 1
    res=modPow(a*a%p, n//2, p)
    if n&1: res=res*a%p
    return res

t=int(input())
for _ in range(t):
    n, k=map(int, input().split())
    k-=2; n-=1

    a=[]; b=[]
    for i in range(40, -1, -1):
        a.append(n//pow(m, i)); n=n%pow(m, i)
        b.append(k//pow(m, i)); k=k%pow(m, i)

    res=1
    for i in range(41):
        if a[i]==b[i]==0: continue
        if a[i]<b[i]: res=0
        else: res*=(fac[a[i]]*modPow(fac[b[i]]*fac[a[i]-b[i]], m-2, m))%m

    print(res%m)