'''
2252번
줄 세우기
'''

import sys
from collections import deque
input=sys.stdin.readline

n, m=map(int, input().split())

indgree=[0]*(n+1); graph={}
for _ in range(m):
    a, b=map(int, input().split())
    if a not in graph: graph[a]=[]
    graph[a].append(b)
    indgree[b]+=1

q=deque()
for i in range(1, n+1):
    if indgree[i]==0:
        q.append(i)

while q:
    node=q.pop()
    if indgree[node]==0:
        print(node, end=' ')
    if node not in graph: continue
    for g in graph[node]:
        indgree[g]-=1
        if indgree[g]==0:
            q.append(g)

print()