'''
12761번
돌다리
'''

from collections import deque
import sys
 
def BFS(start):
    graph={}
    visited={}
    q=deque()
    q.append(start)

    while len(q)>0:
        node=q.popleft()

        if node not in visited:
            visited[node]=True
            q.extend(graph[node])
    return visited

a, b, n, m=map(int, sys.stdin.readline().split())