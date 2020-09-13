'''
11054번
가장 긴 바이토닉 부분 수열
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))

dp=[1]
dp2=[1]
for i in range(1, n):
    m=0
    for j in range(i):
        if a[j]<a[i]:
            m=max(m, dp[j])
    dp.append(m+1)

dp2=[1]*n
for i in range(n-2, -1 ,-1):
    m=0
    for j in range(i+1, n):
        if a[j]<a[i]:
            m=max(m, dp2[j])
    dp2[i]+=m

ans=0
for i in range(n):
    ans=max(dp[i]+dp2[i], ans)
ans-=1
print(ans)