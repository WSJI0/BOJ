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
q.append((0,0,k,0))
visited={}
ans=-1
move=[[1,0],[0,1],[-1,0],[0,-1]]
while q:
    nx, ny, nk=q.popleft()