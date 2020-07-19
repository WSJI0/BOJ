'''
11053번
가장 긴 증가하는 부분 수열
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))

dp=[0]*n
for i in range(n):
    for j in range(i):
        if a[i]>a[j] and dp[i]<dp[j]:
            dp[i]=dp[j]
    dp[i]+=1

print(max(dp))