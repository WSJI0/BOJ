'''
12015번
가장 긴 증가하는 부분 수열 2
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))

dp=[a[0]]
cur=1
ans=0
for i in range(1, n):
    if dp[-1]<a[i]:
        dp.append(a[i])
    elif dp[-1]>a[i]:
        l=0; r=len(dp)-1; res=0
        while l<=r:
            mid=(l+r)//2
            if dp[mid]>a[i]:
                r=mid-1
            elif dp[mid]<a[i]:
                l=mid+1
                res=l
            else:
                res=-1
                break

        if res!=-1:
            dp[res]=a[i]
    ans=max(ans, len(dp))

if ans==0: ans=1
print(ans)