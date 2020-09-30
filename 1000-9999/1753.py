'''
1753번
최단경로

미완성
'''

import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)

V, E=map(int, input().split())
k=int(input())
cost={}
graph={}

for _ in range(E):
    u, v, w=map(int, input().split())
    if (u, v) not in cost: cost[(u, v)]=w
    if u not in graph: graph[u]=[]
    if v not in graph: graph[v]=[]
    cost[(u, v)]=min(cost[(u, v)], w)
    graph[u].append(v)

cost[(0, k)]=0

dp=[-1 for _ in range(V+1)]
dp[k]=0

def dijkstra(n):
    global dp
    if dp[n]!=-1:
        for i in graph[n]:
            if dp[i]==-1:
                dp[i]=cost[(n, i)]+dp[n]
                dijkstra(i)
            else: dp[i]=min(dp[i], cost[(n, i)]+dp[n])

dijkstra(k)

for i in range(1, V+1):
    print(dp[i] if dp[i]!=-1 else "INF")