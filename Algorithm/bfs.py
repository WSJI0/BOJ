'''
BFS
너비 우선 탐색
'''

from collections import deque

graph={
    '0':['1', '4'],
    '1':['1','2'],
    '2':['0','1','2','3','4'],
    '3':['2','4'],
    '4':['0','2','3']
}
 
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

print(BFS(graph,'0'))