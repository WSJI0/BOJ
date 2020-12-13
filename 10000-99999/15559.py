'''
15559번
내 선물을 받아줘
'''

import sys
from collections import deque
input=sys.stdin.readline

parent=[]
for y in range(1000):
    parent.append([])
    for x in range(1000):
        parent[y].append((y, x))

def find(u):
    if u==parent[u[0]][u[1]]: return u
    parent[u[0]][u[1]]=find(parent[u[0]][u[1]])
    return parent[u[0]][u[1]]

def union(u, v):
    u=find(u); v=find(v)
    if u==v: return
    parent[u[0]][u[1]]=v

n, m=map(int, input().split())
board=[]
for i in range(n):
    board.append(list(input().rstrip()))

team=[[0 for _ in range(m)] for _ in range(n)]

move={'S':[1, 0], 'N':[-1, 0], 'E':[0, 1], 'W':[0, -1]}

for y in range(n):
    for x in range(m):
        visited={}
        visited[(y, x)]=True
        q=deque([(y, x)])
        while q:
            ny, nx=q.pop()
            mx=nx+move[board[ny][nx]][1]
            my=ny+move[board[ny][nx]][0]
            if (my, mx) not in visited:
                union((my, mx), (ny, nx))
                visited[(my, mx)]=True
                q.append((my, mx))

res={}
for y in range(n):
    for x in range(m):
        f=find((y, x))
        if f not in res:
            res[f]=True

print(len(res))