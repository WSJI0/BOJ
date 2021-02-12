'''
16933번
벽 부수고 이동하기 3
'''

import sys
from collections import deque
input=sys.stdin.readline

n, m, k=map(int, input().split())

board=[]
for _ in range(n):
    board.append(list(map(int, input().rstrip())))

q=deque()
q.append((0,0,k,0,0))
visited={(0, 0, k, 0): True}
ans=-1
move=[[1,0],[0,1],[-1,0],[0,-1]]
while q:
    node=q.popleft()
    if node[0]==m-1 and node[1]==n-1:
        ans=node[3]
        break
    for v in move:
        mx=v[0]+node[0]
        my=v[1]+node[1]
        mk=node[2]
        if 0<=mx<m and 0<=my<n:
            if board[my][mx]==0:
                if (mx, my, mk, node[3]+1) not in visited:
                    visited[(mx, my, mk, node[3]+1)]=True
                    q.append((mx,my,mk, node[3]+1, (node[4]+1)%2))
            else:
                if node[4]==0 and node[2]>0:
                    if (mx, my, mk-1, node[3]+1) not in visited:
                        visited[(mx, my, mk-1, node[3]+1)]=True
                        q.append((mx,my,mk-1, node[3]+1, (node[4]+1)%2))
                elif node[4]==1 and node[2]>0:
                    if (node[0], node[1], node[2], node[3]+1) not in visited:
                        visited[(node[0], node[1], node[2], node[3]+1)]=True
                        q.append((node[0], node[1], node[2], node[3]+1, (node[4]+1)%2))
    if ans!=-1: break

print(ans+1 if ans>1 else ans)