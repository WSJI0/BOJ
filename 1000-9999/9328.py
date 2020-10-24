'''
9328번
열쇠

미완성
'''

import sys
from collections import deque
input=sys.stdin.readline

move=[[1,0],[0,1],[-1,0],[0,-1]]

t=int(input())
for _ in range(t):
    h, w=map(int, input().split())
    board=[]; ans=0
    for _ in range(h):
        board.append(list(input().rstrip()))
    key=input().rstrip()
    K=(1<<26)-1
    if key!='0':
        for i in key: K&=~(1<<(ord(i)-97))
    visited={}
    for y in range(h):
        for x in range(w):
            if (x==0 or x==w-1 or y==0 or y==h-1) and board[y][x]=='.':
                q=deque()
                q.append((x, y, 0, K))
                while q:
                    node=q.popleft()
                    if (node[0], node[1], node[3]) not in visited or ((node[0], node[1], node[3]) in visited and visited[(node[0], node[1], node[3])]<node[2]):
                        visited[(node[0], node[1], node[3])]=node[2]
                        nx=node[0]; ny=node[1]; nd=node[2]; nk=node[3]
                        ans=max(ans, nd)
                        for m in move:
                            mx=nx+m[0]; my=ny+m[1]
                            if 0<=mx<w and 0<=my<h:
                                if board[my][mx]=='.':
                                    q.append((mx, my, nd, nk))
                                    continue
                                elif board[my][mx]=='*': continue
                                elif board[my][mx]=='$':
                                    q.append((mx, my, nd+1, nk))
                                    continue
                                else:
                                    if board[my][mx].islower():
                                        nk&=~(1<<(ord(board[my][mx])-97))
                                        q.append((mx, my, nd, nk))
                                    else:
                                        if not nk&(1<<(ord(board[my][mx])-65)):
                                            q.append((mx, my, nd, nk))

    print(ans)