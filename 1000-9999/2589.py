'''
2589번
보물섬
'''

import sys
from collections import deque
input=sys.stdin.readline

h, w=map(int, input().split())
board=[]
for _ in range(h):
    board.append(list(input().rstrip()))

def bfs(nn):
    global w, h, board
    q=deque()
    q.append(nn)
    visited={}
    cnt=0
    move=[[1,0],[0,1],[-1,0],[0,-1]]
    while q:
        for _ in range(len(q)):
            node=q.popleft()
            if node not in visited:
                visited[node]=True
                for m in move:
                    mx=m[0]+node[0]
                    my=m[1]+node[1]
                    if 0<=mx<w and 0<=my<h:
                        if board[my][mx]=='L':
                            q.append((mx,my))
        cnt+=1
    return cnt-2

ans=0
for y in range(h):
    for x in range(w):
        if board[y][x]=='L':
            b=bfs((x,y))
            ans=max(ans,b)

print(ans)