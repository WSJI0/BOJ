'''
2637번
장난감조립
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
m=int(input())

indgree=[0]*(n+1); graph={}
for _ in range(m):
    x, y, k=map(int, input().split())
    if y not in graph: graph[y]=[]
    graph[y].append([x, k])
    indgree[x]+=1

q=deque(); dp=[[0 for _ in range(n+1)] for _ in range(n+1)]
for i in range(1, n+1):
    if indgree[i]==0:
        q.append(i)
        dp[i][i]=1

while q:
    node=q.pop()
    if node not in graph: continue
    for g in graph[node]:
        indgree[g[0]]-=1
        if indgree[g[0]]==0:
            q.append(g[0])
        for i in range(1, n+1):
            dp[g[0]][i]+=dp[node][i]*g[1]
        
for i in range(1, n+1):
    if dp[n][i]:
        print(i, dp[n][i])