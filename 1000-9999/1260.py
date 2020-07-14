'''
1260번
DFS와 BFS
'''

import sys
from collections import deque
input=sys.stdin.readline

graph={}
n, m, v=map(int, input().split())
for _ in range(m):
    x, y=map(int, input().split())
    if x not in graph: graph[x]=[]
    if y not in graph: graph[y]=[]
    graph[x].append(y)
    graph[y].append(x)

dfs_visited={}
dfs_stack=deque()
dfs_stack.append(v)
while dfs_stack:
    node=dfs_stack.pop()
    if node not in dfs_visited:
        print(node, end=' ')
        dfs_visited[node]=True
        if node in graph:
            dfs_stack.extend(list(sorted(graph[node], reverse=True)))

print()

bfs_visited={}
bfs_queue=deque()
bfs_queue.append(v)
while bfs_queue:
    node=bfs_queue.popleft()
    if node not in bfs_visited:
        print(node, end=' ')
        bfs_visited[node]=True
        if node in graph:
            bfs_queue.extend(list(sorted(graph[node])))