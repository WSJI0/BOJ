'''
1865번
웜홀
'''

import sys
input=sys.stdin.readline
INF=987654321

def ford(s, n, graph):
    dp=[INF]*(n+1)
    dp[s]=0
    for x in range(n):
        for i in range(1, n+1):
            if i not in graph: continue
            for g in graph[i]:
                if dp[i]+g[1]<dp[g[0]]:
                    dp[g[0]]=dp[i]+g[1]
                    if x==n-1:
                        return True
    return False

tc=int(input())
for _ in range(tc):
    n, m, w=map(int, input().split()) 
    graph={}
    for _ in range(m):
        s, e, t=map(int, input().split())
        if s not in graph: graph[s]=[]
        if e not in graph: graph[e]=[]
        graph[s].append([e, t])
        graph[e].append([s, t])
    for _ in range(w):
        s, e, t=map(int, input().split())
        if s not in graph: graph[s]=[]
        if e not in graph: graph[e]=[]
        graph[s].append([e, -t])

    print("YES" if ford(1, n, graph) else "NO")