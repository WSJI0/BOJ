'''
12727번
Numbers (Small)
'''

import sys
import decimal
input=sys.stdin.readline
decimal.getcontext().prec=100000000000000000

def lpow(a, n):
    res=a
    for _ in range(n-1):
        res*=decimal.Decimal(a)
    return decimal.Decimal(res)

t=int(input())
for i in range(1, t+1):
    n=int(input())
    sol=['263','151','855','527','743','351','135','407','903','791','135','647']
    if n<=18:
        ans=str(int(lpow(3+decimal.Decimal(5**0.5), n)%1000))
        ans=(3-len(ans))*'0'+ans
    else: ans=sol[n-19]
    print("Case #"+str(i)+": "+str(ans))