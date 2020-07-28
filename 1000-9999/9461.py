'''
9461번
파도반 수열
'''

import sys
input=sys.stdin.readline

dp=[1,1,1,2]
for i in range(4, 101):
    dp.append(dp[i-3]+dp[i-2])

t=int(input())
for _ in range(t):
    n=int(input())
    print(dp[n-1])