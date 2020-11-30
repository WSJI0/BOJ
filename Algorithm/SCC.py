'''
SCC(Strongly Connected Comppnent) 강한 연결 요소
'''

import sys
from collections import deque
input=sys.stdin.readline

v, e=map(int, input().split())
scc=[]; vis={}; graph={}; s=[]
for _ in range(e):
    a, b=map(int, input().split())
    if a not in graph: graph[a]=[]
    graph[a].append(b)

for i in range(1, v+1):
    if i in vis: continue
    q=deque([i])
    while q:
        node=q.pop()
        if node not in vis: 
            s.append(node)
        if node in vis:
            scc.append([])
            while s:
                if s[-1] in vis:
                    scc[-1].append(s.pop())
                else: break
            q=deque()
            continue
        vis[node]=True
        for g in graph[node]:
            q.append(g)

print(scc)