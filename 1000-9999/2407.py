'''
2407번
조합
'''

import sys
input=sys.stdin.readline

dp=[[0], [1,1], [1,2,1]]
for i in range(3, 101):
    dp.append([1 for _ in range(i+1)])
    for j in range(i):
        if j==0: dp[i][j]=1
        else: dp[i][j]=dp[i-1][j-1]+dp[i-1][j]

n, r=map(int, input().split())
print(dp[n][r])