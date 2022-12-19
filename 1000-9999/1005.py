'''
1005번
ACM Craft
'''

import sys
input=sys.stdin.readline

def find(n):
    global dp, D, graph
    if n in dp: return dp[n]
    if n not in graph:
        dp[n]=D[n-1]; return dp[n]
    res=0
    for g in graph[n]:
        res=max(res, find(g))
    dp[n]=res+D[n-1]

    return dp[n]

t=int(input())
for _ in range(t):
    n, k=map(int, input().split())
    graph={}; dp={}
    D=list(map(int, input().split()))
    for _ in range(k):
        x, y=map(int, input().split())
        if y not in graph: graph[y]=[]
        graph[y].append(x)
    
    w=int(input())
    for i in range(1, n+1): find(i)
    print(dp[w])