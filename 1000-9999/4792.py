'''
4792번
레드 블루 스패닝 트리
'''

import sys
import heapq
input=sys.stdin.readline

while True:
    n, m, k=map(int, input().split())
    if n==m==k==0: break
    graph={}; color=[[0 for _ in range(1001)] for _ in range(1001)]
    for _ in range(m):
        c, a, b=input().rstrip().split()
        a=int(a); b=int(b)
        if a not in graph: graph[a]=[]
        if b not in graph: graph[b]=[]
        graph[a].append(b)
        graph[b].append(a)
        color[a][b]=color[b][a]='B'
    
    pq=[]; visited={}; res1=0; res2=0
    heapq.heappush(pq, [0, 1])
    while pq:
        p=heapq.heappop(pq)
        if p[1] not in visited:
            visited[p[1]]=True
            res1+=p[0]
            for g in graph[p[1]]:
                cost=0
                if color[a][b]=='B': cost=1
                heapq.heappush(pq, [cost, g])
                
    pq=[]; visited={}
    heapq.heappush(pq, [0, 1])
    while pq:
        p=heapq.heappop(pq)
        if p[1] not in visited:
            visited[p[1]]=True
            res1+=p[0]
            for g in graph[p[1]]:
                cost=0
                if color[a][b]=='R': cost=1
                heapq.heappush(pq, [cost, g])

    print(1 if res2<=k<=res1 else 0)