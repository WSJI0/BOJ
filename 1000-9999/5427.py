'''
5427번
불
'''

import sys
from collections import deque
input=sys.stdin.readline

t=int(input())

for _ in range(t):
    w, h=map(int, input().split())

    board=[]
    for i in range(h):
        board.append(list(input().rstrip()))
    
    player=deque()
    fire=deque()
    for y in range(h):
        for x in range(w):
            if board[y][x]=='@':
                player.append((x,y))
            elif board[y][x]=='*':
                fire.append((x,y))
            elif board[y][x]=='.':
                board[y][x]=99999
    
    cnt2=0
    visited2={}
    move=[[1,0], [0,1], [-1,0], [0,-1]]
    while fire:
        for _ in range(len(fire)):
            n=fire.popleft()
            if n not in visited2:
                visited2[n]=True
                board[n[1]][n[0]]=cnt2
                for m in move:
                    if 0<=n[0]+m[0]<w and 0<=n[1]+m[1]<h and board[n[1]+m[1]][n[0]+m[0]]!='#':
                        fire.append((n[0]+m[0], n[1]+m[1]))
        cnt2+=1

    cnt=0
    visited={}
    escape=False
    while player:
        for _ in range(len(player)):
            n=player.popleft()
            if n not in visited:
                visited[n]=True
                if n[0]==0 or n[0]==w-1 or n[1]==0 or n[1]==h-1:
                    escape=True
                    break
                for m in move:
                    if 0<=n[0]+m[0]<w and 0<=n[1]+m[1]<h:
                        if board[n[1]+m[1]][n[0]+m[0]]!='#' and board[n[1]+m[1]][n[0]+m[0]]!='@' and board[n[1]+m[1]][n[0]+m[0]]-1>cnt:
                            player.append((n[0]+m[0], n[1]+m[1]))
        if escape: break
        cnt+=1

    if escape:
        print(cnt+1)
    else:
        print("IMPOSSIBLE")