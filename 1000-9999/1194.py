'''
1194번
달이 차오른다, 가자.
'''

import sys
from collections import deque
input=sys.stdin.readline

n, m=map(int, input().split())

board=[]
for _ in range(n):
    board.append(list(input().rstrip()))

q=deque()
for y in range(n):
    for x in range(m):
        if board[y][x]=='0':
            q.append((x,y,''))
            board[y][x]='.'

visited={}
cnt=0
escape=False
move=[[1,0],[0,1],[-1,0],[0,-1]]
while q:
    for _ in range(len(q)):
        node=q.popleft()
        if node not in visited:
            if board[node[1]][node[0]]=='1':
                escape=True
                break
            visited[node]=True
            for v in move:
                mx=v[0]+node[0]
                my=v[1]+node[1]
                if 0<=mx<m and 0<=my<n:
                    if board[my][mx]!='#':
                        if board[my][mx] in 'ABCDEF':
                            if chr(ord(board[my][mx])+32) in node[2]:
                                q.append((mx,my,node[2]))
                        elif board[my][mx] in 'abcdef':
                            if board[my][mx] not in node[2]:
                                q.append((mx,my, node[2]+board[my][mx]))
                            else: 
                                q.append((mx,my, node[2]))
                        else:
                            q.append((mx, my, node[2]))
    if escape: break
    cnt+=1

if escape: print(cnt)
else: print(-1)