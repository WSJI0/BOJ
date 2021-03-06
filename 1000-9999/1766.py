'''
1766번
문제집
'''

import sys
import heapq
input=sys.stdin.readline

n, m=map(int, input().split())

graph={}
q=[]; indgree=[0]*(n+1)
for _ in range(m):
    a, b=map(int, input().split())
    if b not in graph: graph[b]=[]
    if a not in graph: graph[a]=[]
    graph[a].append(b)
    indgree[b]+=1

for i in range(1, n+1):
    if not indgree[i]:
        heapq.heappush(q, i)

while q:
    node=heapq.heappop(q)
    if indgree[node]==0:
        print(node, end=' ')
    if node not in graph: continue
    for g in graph[node]:
        indgree[g]-=1
        if indgree[g]==0:
            heapq.heappush(q, g)
    
print()