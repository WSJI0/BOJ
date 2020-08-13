'''
19542번
전단지 돌리기
'''

import sys
from collections import deque
input=sys.stdin.readline

n, s, d=map(int, input().split())
graph={}
for _ in range(n-1):
    x, y=map(int, input().split())
    if x not in graph: graph[x]=[]
    if y not in graph: graph[y]=[]
    graph[x].append(y)
    graph[y].append(x)

q=deque()
q.append(s)
visited=[0]*(n+1)
cnt=0
while q:
    for _ in range(len(q)):
        node=q.popleft()
        if not visited[node]:
            visited[node]=cnt
            q.extend(graph[node])
    cnt+=1

print(visited)

'''
6 1 1
1 2
2 3
2 4
3 5
5 6
'''