'''
2572번
보드게임
'''

import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)

n=int(input())
color=list(input().split())
m, k=map(int, input().split())

road=[]; graph={}
for _ in range(m+1):
    road.append([0 for _ in range(m+1)])

for _ in range(k):
    a, b, c=input().split()
    a=int(a); b=int(b)
    road[a][b]=c
    road[b][a]=c
    if a not in graph: graph[a]=[]
    if b not in graph: graph[b]=[]
    graph[a].append(b)
    graph[b].append(a)

dp=[]
for _ in range(n):
    dp.append([-1 for _ in range(m+1)])

def solve(i, c):
    global dp, n
    if c==n: return 0
    if dp[c][i]!=-1: return dp[c][i]

    for g in graph[i]:
        s=0
        if road[i][g]==color[c]: s=10
        dp[c][i]=max(dp[c][i], solve(g, c+1)+s)
    return dp[c][i]

print(solve(1, 0))