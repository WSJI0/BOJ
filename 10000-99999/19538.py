'''
19538번
루머
'''

import sys
import math
from collections import deque
input=sys.stdin.readline

n=int(input())

graph={}
for i in range(1, n+1):
    graph[i]=[]
for _ in range(n):
    a=list(map(int, input().split()))[:-1]
    for i in range(len(a)):
        for j in range(len(a)):
            if i==j: continue
            graph[a[i]].append(a[j])

m=int(input())
M=list(map(int, input().split()))

ans=[-1]*n
q=deque()
q.extend(M)
visited={}
cnt=0

while q:
    for _ in range(len(q)):
        node=q.popleft()
        if node not in visited:
            visited[node]=True
            ans[node-1]=cnt
            c=0
            for i in graph[node]:
                if ans[i-1]!=-1:
                    c+=1
                if c>=math.ceil(len(graph[i])):
                    q.append(graph[i])
    cnt+=1

print(*ans)