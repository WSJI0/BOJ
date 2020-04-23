'''
7576번
토마토
'''

import sys
from collections import deque

m, n=map(int,sys.stdin.readline().split())

box=[]
visited={}
mm=0
for _ in range(n):
    box.append(list(map(int, sys.stdin.readline().split())))

def BFS(tomato):
    global box, visited, m, n, mm
    day=0
    q=deque()
    for i in range(len(tomato)):
        q.append([tomato[i][0],tomato[i][1],0])
        visited[(tomato[i][0],tomato[i][1])]=1
        while len(q)!=0:
            node=q.popleft()
            if node[0]>0:
                if (node[0]-1,node[1]) not in visited and box[node[1]][node[0]-1]!=-1:
                    visited[(node[0]-1,node[1])]=1
                    q.append([node[0]-1,node[1], node[2]+1])
            if node[0]<m-1:
                if (node[0]+1,node[1]) not in visited and box[node[1]][node[0]+1]!=-1:
                    visited[(node[0]+1,node[1])]=1
                    q.append([node[0]+1,node[1], node[2]+1])
            if node[1]>0:
                if (node[0],node[1]-1) not in visited and box[node[1]-1][node[0]]!=-1:
                    visited[(node[0],node[1]-1)]=1
                    q.append([node[0],node[1]-1, node[2]+1])
            if node[1]<n-1:
                if (node[0],node[1]+1) not in visited and box[node[1]+1][node[0]]!=-1:
                    visited[(node[0],node[1]+1)]=1
                    q.append([node[0],node[1]+1, node[2]+1])
        day+=1
cnt=0
for i in range(n):
    for j in range(m):
        if box[i][j]==1:
            BFS(m-1, n-1)
        elif box[i][j]==-1:
            cnt+=1

if len(visited)+cnt==n*m:
    print(mm)
else:
    print(-1)