'''
1654번
랜선 자르기
'''

import sys
input=sys.stdin.readline

k, n=map(int, input().split())

a=[]
for _ in range(k):
    a.append(int(input()))

l=1
r=max(a)

while(l<=r):
    num=0
    mid=(l+r)//2

    for i in a:
        num+=(i//mid)

    if num>=n:
        ans=mid
        l=mid+1
    else:
        r=mid-1
    
print(ans)