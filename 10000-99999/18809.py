'''
18809번
Gaaaaaaaaaarden
'''

import sys
from collections import deque
input=sys.stdin.readline

n, m, g, r=map(int, input().split())
board=[]
for _ in range(n):
    board.append(list(map(int, input().split())))

d=[]
for y in range(n):
    for x in range(m):
        if board[y][x]==2: d.append((x, y))
print(d)

def bfs(gq, rq):
    print(gq, rq)

gq=deque()
rq=deque()
def backT(i):
    global gq, rq, g, r, d
    if i==g+r:
        bfs(gq, rq)
        return
    for j in d:
        if i<g:
            gq.append(j)
            backT(i+1)
            gq.pop()
        else:
            rq.append(j)
            backT(i+1)
            rq.pop()

backT(0)