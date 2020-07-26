'''
1981번
배열에서 이동
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())

board=[]
for _ in range(n):
    board.append(list(map(int, input().split())))

def bfs(l, r):
    global board, left, right
    q=deque()
    visited={}
    q.append((0,0))
    move=[[1,0],[0,1],[-1,0],[0,-1]]
    result=False
    while q:
        nx, ny=q.popleft()
        if (nx,ny) not in visited:
            visited[(nx,ny)]=board[ny][nx]
            if nx==n-1 and ny==n-1:
                result=True
                break
            for m in move:
                mx=m[0]+nx
                my=m[1]+ny
                if 0<=mx<n and 0<=my<n and (mx,my) not in visited:
                    if l<=board[my][mx]<=r:
                        q.append((mx,my))

    return result

maxV=0
minV=99999
for y in range(n):
    for x in range(n):
        maxV=max(maxV, board[y][x])
        minV=min(minV, board[y][x])

maxL=min(board[0][0], board[-1][-1])
minR=max(board[0][0], board[-1][-1])
l=minV; r=minR
ans=99999
while minV<=l<=maxL and minR<=r<=maxV:
    if bfs(l, r):
        ans=min(ans, r-l)
        l+=1
    else:
        r+=1
        
print(ans)