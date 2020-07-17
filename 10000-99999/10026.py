'''
10026번
적록색약
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
board=[]
for _ in range(n):
    board.append(list(input().rstrip()))

visited={}
area=0
move=[[1,0],[0,1],[-1,0],[0,-1]]
for y in range(n):
    for x in range(n):
        if (x,y) not in visited:
            q=deque()
            q.append((x,y))
            while q:
                node=q.pop()
                if node not in visited:
                    visited[node]=True
                    for m in move:
                        mx=m[0]+node[0]
                        my=m[1]+node[1]
                        if 0<=mx<n and 0<=my<n:
                            if board[my][mx]==board[node[1]][node[0]]:
                                q.append((mx, my))
            area+=1
print(area, end=' ')

visited={}
area=0
move=[[1,0],[0,1],[-1,0],[0,-1]]
for y in range(n):
    for x in range(n):
        if (x,y) not in visited:
            q=deque()
            q.append((x,y))
            while q:
                node=q.pop()
                if node not in visited:
                    visited[node]=True
                    for m in move:
                        mx=m[0]+node[0]
                        my=m[1]+node[1]
                        if 0<=mx<n and 0<=my<n:
                            if board[my][mx]==board[node[1]][node[0]]:
                                q.append((mx, my))
                            elif board[my][mx]=='R' and board[node[1]][node[0]]=='G':
                                q.append((mx, my))
                            elif board[my][mx]=='G' and board[node[1]][node[0]]=='R':
                                q.append((mx, my))
            area+=1

print(area)