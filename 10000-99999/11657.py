'''
11657번
타임머신
'''

import sys
input=sys.stdin.readline
INF=987654321

n, m=map(int, input().split())

graph={}
for _ in range(m):
    a, b, c=map(int, input().split())
    if a not in graph: graph[a]=[]
    graph[a].append([b, c])


def ford(s):
    dist=[INF]*(n+1)
    dist[s]=0 #시작 노드 0으로

    for _ in range(n-1):
        for i in range(1, n+1):
            if i not in graph: continue
            for nxt, cost in graph[i]:
                if dist[i]==INF: continue
                if dist[nxt]>cost+dist[i]:
                    dist[nxt]=cost+dist[i]

    for i in range(1, n+1): #음의 사이클이 존재하는지 찾기 위해 한번더 돌림
        if i not in graph: continue
        for nxt, cost in graph[i]:
            if dist[nxt]==INF: continue
            if dist[nxt]>cost+dist[i]: # 테이블이 갱신됨
                print(-1)
                sys.exit()

    return dist


res=ford(1)
for i in range(2, n+1):
    print(res[i] if res[i]!=INF else -1)