'''
1197번
최소 스패닝 트리
'''

import sys
import heapq
input=sys.stdin.readline

v, e=map(int, input().split())
graph={}
cost={}
for _ in range(e):
    a, b, c=map(int, input().split())
    if a not in graph: graph[a]=[]
    if b not in graph: graph[b]=[]
    graph[a].append(b)
    graph[b].append(a)
    cost[(a, b)]=c
    cost[(b, a)]=c

pq=[]
heapq.heappush(pq, [0, 1])
ans=0
visited={}
while pq:
    p=heapq.heappop(pq)
    if p[1] not in visited:
        visited[p[1]]=True
        ans+=p[0]
        for g in graph[p[1]]:
            heapq.heappush(pq, [cost[(p[1], g)], g])

print(ans)