'''
1175번
배달
'''

import sys
from collections import deque
input=sys.stdin.readline

n, m=map(int, input().split())
board=[]
q=deque()
for i in range(n):
    l=list(input().rstrip())
    board.append(l)

c=1
for y in range(n):
    for x in range(m):
        if board[y][x]=='C':
            board[y][x]='C'+str(c)
            c+=1
        elif board[y][x]=='S':
            board[y][x]='.'
            q.append((x,y,0,0,0))

visited={}
move=[[0,0],[0,-1],[1,0],[0,1],[-1,0]]
cnt=0
ans=False
while q:
    for _ in range(len(q)):
    #x y direction c1 c2
    #1북 2동 3남 4서
        node=q.popleft()
        if node not in visited:
            x=node[0]; y=node[1]; d=node[2]; c1=node[3]; c2=node[4]
            visited[node]=True
            if c1 and c2:
                ans=True
                break
            for v in range(1, 5):
                if d==v: continue
                mx=x+move[v][0]
                my=y+move[v][1]
                c1=node[3]
                c2=node[4]
                if 0<=mx<m and 0<=my<n and board[my][mx]!='#':
                    if board[my][mx]=='C1': c1=1
                    elif board[my][mx]=='C2': c2=1
                    q.append((mx,my,v,c1,c2))
    if ans: break
    cnt+=1

if ans:
    print(cnt)
else:
    print(-1)