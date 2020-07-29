'''
13460번
구슬 탈출 2

미완성
'''

import sys
from collections import deque
input=sys.stdin.readline

n, m=map(int, input().split())

board=[]
q=deque()
for _ in range(n):
    board.append(list(input().rstrip()))

coor=[0,0,0,0]
for y in range(n):
    for x in range(m):
        if board[y][x]=='B':
            coor[0]=x; coor[1]=y
        elif board[y][x]=='R':
            coor[2]=x; coor[3]=y
q.append(tuple(coor))

visited={}
move=[[1,0],[0,1],[-1,0],[0,-1]]
cnt=0
ans=0
while q:
    for _ in range(len(q)):
        node=q.popleft()
        if board[node[1]][node[0]]=='O': 
            ans=cnt
            break
        if node not in visited:
            visited[node]=True
            for v in move:
                bx=node[0]+v[0]
                by=node[1]+v[1]
                rx=node[2]+v[0]
                ry=node[3]+v[1]
                if 0<=bx<m and 0<=by<n and 0<=rx<m and 0<=ry<n:
                    if board[by][bx]!='#' and board[ry][rx]!='#' and board[by][bx]!='O':
                        q.append((bx,by,rx,ry))
    if ans: break
    cnt+=1
if ans:
    print(ans)
else:
    print(-1)