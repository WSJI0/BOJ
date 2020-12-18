'''
13905번
세부
'''

import sys
import heapq
input=sys.stdin.readline

graph={}
cost={}
n, m=map(int, input().split())
s, e=map(int, input().split())
for i in range(m):
    h1, h2, k=map(int, input().split())
    if h1 not in graph: graph[h1]=[]
    if h2 not in graph: graph[h2]=[]
    graph[h1].append(h2)
    graph[h2].append(h1)
    cost[(h1, h2)]=k
    cost[(h2, h1)]=k

pq=[]
heapq.heappush(pq, [0, s])
dp=[-1 for _ in range(n+1)]
dp[s]=999999999
while pq:
    tmp, p=heapq.heappop(pq)
    if p not in graph: continue
    for g in graph[p]:
        if dp[g]>=min(dp[p], cost[(p, g)]): continue
        dp[g]=min(dp[p], cost[(p, g)])
        heapq.heappush(pq, [dp[g], g])

print(dp[e])