'''
2019번
다각형개수

미완성
'''

import sys
from collections import deque
input=sys.stdin.readline

graph={}
n=int(input())
for _ in range(n):
    sx, sy, ex, ey=map(int, input().split())
    if (sx,sy) not in graph: graph[(sx,sy)]=[]
    if (ex,ey) not in graph: graph[(ex,ey)]=[]
    graph[(sx,sy)].append((ex,ey))
    graph[(ex,ey)].append((sx,sy))

cnt=0
q=deque()
visited={}
for g in graph:
    q.append(g)
    find=0
    while q:
        node=q.pop()
        if g in graph[node]:
            if find==1:
                cnt+=1
            find+=1
        q.extend(graph[node])


print(cnt)