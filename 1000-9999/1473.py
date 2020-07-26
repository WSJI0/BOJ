'''
1473번
미로 탈출

미완성
'''

import sys
from collections import deque
input=sys.stdin.readline

n, m=map(int, input().split())
board=[]
for _ in range(n):
    board.append(list(input().rstrip()))

q=deque()
visited={}
move=[[1,0],[0,1],[-1,0],[0,-1]]
while q:
    node=q.popleft()
    if node not in visited:
        visited[node]=True
        for v in move:
            mx=v[0]+node[0]
            my=v[1]+node[1]
            if 0<=mx<m and 0<=my<n:
                if board[my][mx]=='A':
                    q.append((mx, my, node[2]+1))
                elif board[my][mx]=='C':

