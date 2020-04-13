'''
1904번
01타일
'''

import sys

n=int(sys.stdin.readline())

dp=[0]*1000001
dp[1]=1
dp[2]=2
for i in range(3,n+1):
    dp[i]=dp[i-2]%15746+dp[i-1]%15746

print(dp[n]%15746)