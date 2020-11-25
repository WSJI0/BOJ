'''
1219번
오민식의 고민
'''

import sys
from collections import deque
input=sys.stdin.readline
INF=987654321

def check(i):
    global graph, dist
    q=deque([i]); visited={}
    while q:
        node=q.pop()
        if node==e:
            return True
        visited[node]=True
        for nxt, cost in graph[node]:
            if nxt not in visited:
                q.append(nxt)
    return False

def solve():
    global graph, dist
    dist[s]=0
    for _ in range(n-1):
        for i in range(n):
            for nxt, cost in graph[i]:
                if dist[i]==INF: continue
                if dist[nxt]>dist[i]+cost:
                    dist[nxt]=dist[i]+cost
    tmp=dist[e]
    if tmp==INF: 
        print("gg")
        return
    for i in range(n):
        for nxt, cost in graph[i]:
            if dist[i]==INF: continue
            if dist[nxt]>dist[i]+cost:
                dist[nxt]=dist[i]+cost
                if check(nxt):
                    print("Gee")
                    return
    print(-dist[e]+vil[s])

graph={}
n, s, e, m=map(int, input().split())
for _ in range(m):
    a, b, c=map(int, input().split())
    if a not in graph: graph[a]=[]
    graph[a].append([b, c])
vil=list(map(int, input().split()))

for i in range(n):
    if i not in graph: graph[i]=[]
    for g in graph[i]:
        g[1]-=vil[g[0]]
dist=[INF]*n

solve()