'''
BFS
너비 우선 탐색
'''

from collections import deque

graph={}
 
def BFS(graph, start):
    visited={}
    q=deque()
    q.append(start)

    while len(q)>0:
        node=q.popleft()
        if node not in visited:
            visited[node]=True
            q.extend(graph[node])
    return visited

print(BFS(graph,'1'))