'''
14466번
소가 길을 건너간 이유 6
'''

import sys
from collections import deque
input=sys.stdin.readline

n, k, r=map(int, input().split())
graph={}
for _ in range(r):
    r1, c1, r2, c2=map(int, input().split())
    if (r1, c1) not in graph: graph[(r1, c1)]=[]
    if (r2, c2) not in graph: graph[(r2, c2)]=[]
    graph[(r1, c1)].append((r2, c2))
    graph[(r2, c2)].append((r1, c1))

cow=[]
for _ in range(k):
    a, b=map(int, input().split())
    cow.append((a, b))

ans=0
for i in range(k):
    for j in range(i+1, k):
        q=deque([cow[i]])
        visited={cow[i]:True}
        can=False
        while q:
            node=q.popleft()
            if node==cow[j]:
                can=True
                break
            for g in graph[node]:
                if g not in visited:
                    q.append(g)
                    visited[g]=True

        if not can: ans+=1
print(ans)
