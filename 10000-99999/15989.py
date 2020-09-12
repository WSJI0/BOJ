'''
15989번
1, 2, 3 더하기 4
'''

import sys
input=sys.stdin.readline

dp=[[0,0,0], [1,0,0], [1,1,0], [1,1,1]]
for i in range(4, 10001):
    dp.append([1, dp[i-2][0]+dp[i-2][1], sum(dp[i-3])])

t=int(input())
for i in range(t):
    n=int(input())
    print(sum(dp[n]))