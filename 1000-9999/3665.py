'''
3665번
최종 순위

미완성
'''

import sys
import heapq
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n=int(input())
    t=list(map(int, input().split()))

    s=[0]*(n+1); indgree=[0]*(n+1)
    for i in range(n):
        s[t[i]]=i

    m=int(input())
    graph={}
    for _ in range(m):
        a, b=map(int, input().split())
        if s[a]>s[b]:
            if a not in graph: graph[a]=[]
            graph[a].append(b)
            indgree[b]+=1
        else:
            if b not in graph: graph[b]=[]
            graph[b].append(a)
            indgree[a]+=1
    print(indgree)

    q=[]
    for i in range(1, n+1):
        if indgree[i]==0:
            heapq.heappush(q, [s[i], i])

    ans=[]
    while q:
        node=heapq.heappop(q)[1]
        if indgree[node]==0:
            ans.append(node)
        if node not in graph: continue
        for g in graph[node]:
            indgree[g]-=1
            if indgree[g]==0:
                heapq.heappush(q, [s[g], g])

    print(*ans if len(ans)==n else "IMPOSSIBLE")
    print("-----------")