'''
2512번
예산
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
m=int(input())

l=0
r=max(a)

while(l<=r):
    mid=(l+r)//2
    money=0
    for i in a:
        money+=min(i, mid)
    if money<=m:
        ans=mid
        l=mid+1
    else:
        r=mid-1

print(ans)