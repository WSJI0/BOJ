'''
2573번
빙산
'''

import sys
from collections import deque
input=sys.stdin.readline

n, m=map(int, input().split())
board=[]
for _ in range(n):
    board.append(list(map(int, input().split())))

q=deque()
for y in range(n):
    for x in range(m):
        if board[y][x]!=0:
            q.append((x,y))

year=0
while True:
    year+=1
    visited={}
    move=[[1,0],[0,1],[-1,0],[0,-1]]
    ice=deque()
    while q:
        node=q.popleft()
        if node not in visited:
            cnt=0
            visited[node]=True
            for v in move:
                mx=v[0]+node[0]
                my=v[1]+node[1]
                if board[my][mx]==0 and (mx, my) not in visited:
                    cnt+=1
                else:
                    q.append((mx, my))
            board[node[1]][node[0]]=max(0, board[node[1]][node[0]]-cnt)
            if board[node[1]][node[0]]>0:
                ice.append((node[0], node[1]))
    q=ice
    print("--------------")
    for i in board:
        print(*i)