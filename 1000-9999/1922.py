'''
1992번
네트워크 연결
'''

import sys
import heapq
input=sys.stdin.readline

n=int(input())
m=int(input())
graph=[[] for _ in range(1001)]
cost=[[0 for _ in range(1001)] for _ in range(1001)]
for _ in range(m):
    a, b, c=map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    cost[a][b]=c; cost[b][a]=c

pq=[]; ans=0
visited={}
heapq.heappush(pq, [0, 1])
while pq:
    node=heapq.heappop(pq)
    if node[1] not in visited:
        visited[node[1]]=True
        ans+=node[0]
        for g in graph[node[1]]:
            heapq.heappush(pq, [cost[node[1]][g], g])
        
print(ans)