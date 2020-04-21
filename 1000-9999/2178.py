'''
2178번
미로 탐색
'''

from collections import deque

maze=[]
n, m=map(int, input().split())

for i in range(n):
    M=input()
    maze.append(list(map(int,M)))

q=deque()

q.append([0,0,0])
visited={}

while len(q)!=0:
    node=q.popleft()
    if node[0]==m-1 and node[1]==n-1:
        print(node[2]+1)
        break
    if node[0]+1<m and (node[0]+1, node[1]) not in visited:
        if maze[node[1]][node[0]+1]==1:
            visited[(node[0]+1, node[1])]=1
            q.append([node[0]+1, node[1], node[2]+1])
    if node[0]-1>=0 and (node[0]-1, node[1]) not in visited:
        if maze[node[1]][node[0]-1]==1:
            visited[(node[0]-1, node[1])]=1
            q.append([node[0]-1, node[1], node[2]+1])
    if node[1]+1<n and (node[0], node[1]+1) not in visited:
        if maze[node[1]+1][node[0]]==1:
            visited[(node[0], node[1]+1)]=1
            q.append([node[0], node[1]+1, node[2]+1])
    if node[1]-1>=0 and (node[0], node[1]-1) not in visited:
        if maze[node[1]-1][node[0]]==1:
            visited[(node[0], node[1]-1)]=1
            q.append([node[0], node[1]-1, node[2]+1])