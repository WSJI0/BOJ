'''
1912번
연속합
'''

import sys

n=int(sys.stdin.readline())
a=list(map(int, sys.stdin.readline().split()))

dp=[0]*n
dp[0]=a[0]
for i in range(1, n):
    dp[i]=max(0, dp[i-1])+a[i]

print(max(dp))