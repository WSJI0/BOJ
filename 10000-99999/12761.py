'''
12761번
돌다리
'''

from collections import deque
import sys

def BFS(start, end):
    global a,b
    visited={}
    q=deque()
    q.append([start,0])

    while len(q)>0:
        node=q.popleft()
        if node[0]==end:
            return node[1]
        if node[0]+1<=100000 and (node[0]+1) not in visited:
            visited[node[0]+1]=1
            q.append([node[0]+1, node[1]+1])
        if node[0]-1>=0 and (node[0]-1) not in visited:
            visited[node[0]-1]=1
            q.append([node[0]-1, node[1]+1])
        if node[0]+a<=100000 and (node[0]+a) not in visited:
            visited[node[0]+a]=1
            q.append([node[0]+a, node[1]+1])
        if node[0]+b<=100000 and (node[0]+b) not in visited:
            visited[node[0]+b]=1
            q.append([node[0]+b, node[1]+1])
        if node[0]-a>=0 and (node[0]-a) not in visited:
            visited[node[0]-a]=1
            q.append([node[0]-a, node[1]+1])
        if node[0]-b>=0 and (node[0]-b) not in visited:
            visited[node[0]-b]=1
            q.append([node[0]-b, node[1]+1])
        if node[0]*a<=100000 and (node[0]*a) not in visited:
            visited[node[0]*a]=1
            q.append([node[0]*a, node[1]+1])
        if node[0]*b<=100000 and (node[0]*b) not in visited:
            visited[node[0]*b]=1
            q.append([node[0]*b, node[1]+1])


a, b, n, m=map(int, sys.stdin.readline().split())
print(BFS(n,m))