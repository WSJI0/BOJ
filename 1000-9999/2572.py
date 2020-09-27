'''
2572번
보드게임

미완성
'''

import sys
input=sys.stdin.readline

n=int(input())
color=[0]+list(input().split())
m, k=map(int, input().split())

road=[]; graph={}
for _ in range(n):
    road.append([0 for _ in range(n)])

for _ in range(k):
    a, b, c=input().rstrip().split()
    a=int(a); b=int(b)
    road[a-1][b-1]=c
    road[b-1][a-1]=c
    if a not in graph: graph[a]=[]
    if b not in graph: graph[b]=[]
    graph[a].append(b); graph[b].append(a)

dp={1: 0}; visit=False
def score(i):
    global visit
    if i in dp: return dp[i]
    res=0
    for g in graph[i]:
        if color[g]==color[i]:
            res+=10
        res+=score(g)
    dp[i]=res
    return dp[i]

for i in range(1, n+1):
    score(i)
print(dp[1])