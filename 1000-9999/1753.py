'''
1753번
최단경로

시간초과
'''

import sys
import heapq
input=sys.stdin.readline
sys.setrecursionlimit(10**9)

V, E=map(int, input().split())
K=int(input())

graph={}
cost={}
dp=[9999999999]*(V+1)
for _ in range(E):
    u, v, w=map(int, input().split())
    if u not in graph: graph[u]=[]
    graph[u].append(v)
    if (u, v) not in cost: cost[(u, v)]=w
    else: cost[(u, v)]=min(cost[(u, v)], w)

visited={}
def dijkstra(n):
    global dp, visited
    visited[n]=dp[n]; q=[]
    for i in graph[n]:
        dp[i]=min(dp[i], dp[n]+cost[(n, i)])
        if (i not in visited or (i in visited and visited[i]<=dp[i])) and i in graph: heapq.heappush(q, [cost[(n, i)],i])
    for i in range(len(q)):
        dijkstra(heapq.heappop(q)[1])

dp[K]=0
dijkstra(K)
for i in range(1, V+1):
    print(dp[i] if dp[i]!=9999999999 else "INF")