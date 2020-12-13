'''
1516번
게임 개발
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())

bT=[0]*(n+1); graph={}; indgree=[0]*(n+1)
for i in range(1, n+1):
    a=list(map(int, input().split()))
    bT[i]=a[0]
    for j in range(1, len(a)-1):
        if a[j] not in graph: graph[a[j]]=[]
        graph[a[j]].append(i)
        indgree[i]+=1

ans=[]
for i in range(n+1): ans.append(bT[i])
q=deque()
for i in range(1, n+1):
    if indgree[i]==0:
        q.append(i)

while q:
    node=q.popleft()
    if node not in graph: continue
    for g in graph[node]:
        indgree[g]-=1
        ans[g]=max(ans[g], bT[g]+ans[node])
        if indgree[g]==0:
            q.append(g)

for i in range(1, n+1):
    print(ans[i])