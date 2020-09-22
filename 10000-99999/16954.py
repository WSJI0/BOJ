'''
16954번
움직이는 미로 탈출
'''

import sys
from collections import deque
input=sys.stdin.readline

board=[]
for _ in range(8):
    board.append(list(input().rstrip()))

wall=deque()
for y in range(8):
    for x in range(8):
        if board[y][x]=='#':
            wall.append((x, y))
            board[y][x]=[0]
        else:
            board[y][x]=['.']

cnt=0
while wall:
    for _ in range(len(wall)):
        n=wall.popleft()
        board[n[1]][n[0]].append(cnt)
        if n[1]!=7:
            wall.append((n[0], n[1]+1))
    cnt+=1

q=deque()
q.append((0,7,0))
visited={}
move=[[0,0],[0,-1],[1,0],[-1,0],[1,1],[-1,1],[-1,-1],[1,-1]]
find=False
while q:
    n=q.popleft()
    if n[0]==7 and n[1]==0:
        find=True
    if n not in visited:
        visited[n]=True
        for m in move:
            mx=m[0]+n[0]
            my=m[1]+n[1]
            if 0<=mx<8 and 0<=my<8:
                if board[my][mx]!=['.']:
                    if n[2] not in board[my][mx] and (n[2]+1) not in board[my][mx]:
                        q.append((mx, my, n[2]+1))
                else: q.append((mx, my, n[2]+1))
    if find: break

print(1 if find else 0)