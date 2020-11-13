'''
14938번
서강그라운드
'''

import sys
input=sys.stdin.readline

n, m, r=map(int, input().split())
t=list(map(int, input().split()))

dp=[[999999999 for _ in range(n+1)] for _ in range(n+1)]
for _ in range(r):
    a, b, l=map(int, input().split())
    dp[a][b]=l
    dp[b][a]=l

for k in range(1, n+1): #pass
    for i in range(1, n+1): #start
        for j in range(1, n+1): #end
            if dp[i][j]>dp[i][k]+dp[k][j]:
                dp[i][j]=dp[i][k]+dp[k][j]

ans=0
for i in range(1, n+1):
    res=t[i-1]
    for j in range(1, n+1):
        if i==j: continue
        if dp[i][j]<=m: res+=t[j-1]
    ans=max(ans, res)

print(ans)