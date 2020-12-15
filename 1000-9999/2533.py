'''
2533번
사회망 서비스(SNS)

미완성
'''

import sys
input=sys.stdin.readline

n=int(input())
graph={}; indgree=[0]*(n+1)
for _ in range(n-1):
    a, b=map(int, input().split())
    if b not in graph: graph[b]=[]
    graph[b].append(a)
    indgree[a]+=1

res={}
for i in range(1, n+1):
    if indgree[i] not in res: res[indgree[i]]=[]
    res[indgree[i]].append(i)

dp={}
s=list(sorted(res.keys()))
cnt=0
for i in s:
    cnt+=1
    if cnt%2==0: continue
    for r in res[i]:
        if r not in graph: continue
        for g in graph[r]:
            if g not in dp:
                dp[g]=True

print(len(dp))