'''
14502번
연구소
'''

import sys
import copy
from collections import deque
input=sys.stdin.readline

board=[]
n, m=map(int, input().split())
for _ in range(n):
    board.append(list(map(int, input().split())))

move=[[1,0],[0,1],[-1,0],[0,-1]]
ans=0

virus=deque()
zero=deque()
w=3
for y in range(n):
    for x in range(m):
        if board[y][x]==2:
            virus.append([x,y])
        elif board[y][x]==0:
            zero.append([x,y])
        else:
            w+=1

ans=99999
def bfs(board):
    global virus, ans
    q=deque()
    q.extend(virus)
    visited={}
    while q:
        node=q.popleft()
        if (node[0], node[1]) not in visited:
            visited[(node[0], node[1])]=True
            for v in move:
                if 0<=node[0]+v[0]<m and 0<=node[1]+v[1]<n:
                    if board[node[1]+v[1]][node[0]+v[0]]==0:
                        q.append([node[0]+v[0], node[1]+v[1]])
    ans=min(len(visited),ans)

def wall(k):
    global n, m, board
    if k==3: 
        bfs(board)
        return
    for y in range(n):
        for x in range(m):
            if board[y][x]==0:
                board[y][x]=1
                wall(k+1)
                board[y][x]=0

for w1 in range(len(zero)):
    for w2 in range(w1+1, len(zero)):
        for w3 in range(w2+1, len(zero)):
            board2=copy.deepcopy(board)
            board2[zero[w1][1]][zero[w1][0]]=1
            board2[zero[w2][1]][zero[w2][0]]=1
            board2[zero[w3][1]][zero[w3][0]]=1
            bfs(board2)

print(n*m-ans-w)