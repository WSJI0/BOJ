'''
15988번
1, 2, 3 더하기 3
'''

import sys
input=sys.stdin.readline

dp=[0, 1, 2, 4]
for i in range(4, 1000001):
    dp.append((dp[i-1]+dp[i-2]+dp[i-3])%1000000009)

t=int(input())
for _ in range(t):
    n=int(input())
    print(dp[n])