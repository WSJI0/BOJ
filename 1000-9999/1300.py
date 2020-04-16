'''
1300번
K번째 수
'''

import sys

n=int(sys.stdin.readline())
k=int(sys.stdin.readline())

l=1
r=k

ans=0
while l<=r:
    cnt=0
    mid=(l+r)//2
    for i in range(1, n+1):
        if mid//i<n:
            cnt+=mid//i
        else:
            cnt+=n
    if cnt<k:
        l=mid+1
    else:
        ans=mid
        r=mid-1

print(ans)