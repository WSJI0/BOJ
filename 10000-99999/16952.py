'''
16952번
체스판 여행 2

미완성
'''

import sys
from collections import deque
input=sys.stdin.readline

board=[]
q=deque()
n=int(input())
for i in range(n):
    board.append(list(map(int, input().split())))
    if board[i].count(1)!=0: 
        q.append((board[i].index(1), i, 0, 0))
        q.append((board[i].index(1), i, 1, 0))
        q.append((board[i].index(1), i, 2, 0))

visited={}; cnt=0; find=False
knight=[[2, 1], [1, 2], [2, -1], [-1, 2], [-2, 1], [1, -2], [-2, -1], [-1, -2]]
while q:
    for _ in range(len(q)):
        node=q.popleft()
        #x, y, 현재 말(0=나이트, 1=비숍, 2=퀸), 바꾼 횟수
        nx=node[0]; ny=node[1]; nd=node[2]; nc=node[3]
        if (nx, ny, nd) not in visited or ((nx, ny, nd) in visited and nc[(nx, ny, nd)]>nc):
            if board[ny][nx]==n*n:
                find=True
            for v in knight:

    if find: break
    cnt+=1