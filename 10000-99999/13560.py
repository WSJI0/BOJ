'''
13560번
축구 게임
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
a.sort()
ans=1
a=[0]+a
pSum=0
for i in range(1, n+1):
    pSum+=a[i]
    if i*(i-1)//2>pSum: ans=-1
if pSum!=n*(n-1)//2: ans=-1

print(ans)