'''
1967번
트리의 지름
'''

import sys
from collections import deque
input=sys.stdin.readline

graph={}
n=int(input())
ans=0; cost=[0]*(n+1); indgree=[0]*(n+1)

for _ in range(n-1):
    a, b, c=map(int, input().split())
    if b not in graph: graph[b]=[]
    graph[b].append([a, c])
    indgree[a]+=1

level=[[] for _ in range(10001)]
for i in range(1, n+1):
    level[indgree[i]].append(i)
    if indgree[i]==0:
        for g in graph[i]:
            ans=max(ans, cost[g[0]]+g[1])
            cost[g[0]]=max(cost[g[0]], g[1])

for i in range(1, n+1):
    if not level[i]: break
    print(level[i])
    for l in level[i]:
        if l not in graph: break
        for g in graph[l]:
            ans=max(ans, cost[g[0]]+g[1])
            cost[g[0]]=max(cost[g[0]], g[1])

print(cost)
