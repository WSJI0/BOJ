'''
플로이드 와샬
'''

import sys
input=sys.stdin.readline
INF=987654321

n, m=map(int, input().split())

dp=[[INF for _ in range(n+1)] for _ in range(n+1)]
for _ in range(m):
    a, b, c=map(int, input().split())
    dp[a][b]=c

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if dp[i][j]>dp[i][k]+dp[k][j]:
                dp[i][j]=dp[i][k]+dp[k][j]

for i in range(2, n+1):
    print(dp[1][i])