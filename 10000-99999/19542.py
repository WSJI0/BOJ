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
visited={}
cnt=0
while q:
    node=q.pop()
    for _ in range(len(q)):
        if node not in visited:
            visited[node]=True
            for _ in range(d):
                for i in graph[node]:
                    if i not in visited:
                        q.append(i)
    cnt+=1

print(cnt)