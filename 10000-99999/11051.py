'''
11051번
이항 계수 2
'''

import sys
input=sys.stdin.readline

n, k=map(int, input().split())

fac=[1]
for i in range(1, n+1):
    fac.append(fac[i-1]*i)

print(fac[n]//(fac[n-k]*fac[k])%10007)