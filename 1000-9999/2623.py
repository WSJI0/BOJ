'''
2623번
음악프로그램
'''

import sys
from collections import deque
input=sys.stdin.readline

n, m=map(int, input().split())
indgree=[0]*(n+1); graph={}

for _ in range(m):
    o=list(map(int, input().split()))
    for i in range(1, len(o)-1):
        if o[i] not in graph:
            graph[o[i]]=[]
        graph[o[i]].append(o[i+1])
        indgree[o[i+1]]+=1

q=deque()
for i in range(1, n+1):
    if indgree[i]==0:
        q.append(i)

ans=[]
while q:
    node=q.pop()
    if indgree[node]==0:
        ans.append(node)
    if node not in graph: continue
    for g in graph[node]:
        indgree[g]-=1
        if indgree[g]==0:
            q.append(g)

if len(ans)==n:
    for i in ans: print(i)
else: print(0)