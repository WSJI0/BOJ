'''
10986번
나머지 합

미완성
'''

import sys
input=sys.stdin.readline

n, m=map(int, input().split())
a=list(map(int, input().split()))

pSum=[0]
for i in range(1, n+1):
    pSum.append((pSum[i-1]+a[i-1]%m)%m)

cnt=-1
for i in range(1, n+1):
    if pSum[i]==0:
        cnt+=1
    if pSum[i-1]==0:
        cnt+=1

print(cnt)