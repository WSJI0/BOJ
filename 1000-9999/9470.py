'''
9470번
Strahler 순서
'''

import sys
from collections import deque
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    k, m, p=map(int, input().split())
    indgree=[0]*(m+1)
    graph={}
    for _ in range(p):
        a, b=map(int, input().split())
        if a not in graph: graph[a]=[]
        graph[a].append(b)
        indgree[b]+=1

    q=deque()
    for i in range(1, m+1):
        if indgree[i]==0:
            q.append(i)

    res=[0]*(m+1)
    cnt=0
    while q:
        cnt+=1
        for _ in range(len(q)):
            node=q.pop()
            if indgree[node]==0:
                res[node]=cnt
            if node not in graph: continue
            for g in graph[node]:
                indgree[g]-=1
                if indgree[g]==0:
                    q.append(g)

    for i in range(len(res)):
        if res[i][0] not in graph: continue
        for g in graph[res[i][0]]:
            if res[g]==res[i][1]-1