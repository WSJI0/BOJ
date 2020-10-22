'''
17130번
토끼가 정보섬에 올라온 이유
'''

import sys
sys.setrecursionlimit(10**9)
input=sys.stdin.readline

n, m=map(int, input().split())
board=[]
for _ in range(n):
    board.append(list(input().rstrip()))
hole=[]
for y in range(n):
    for x in range(m):
        if board[y][x]=='R':
            rabit=[x, y]
        elif board[y][x]=='O':
            hole.append([x, y])

dp=[]
for _ in range(n): dp.append([-1 for _ in range(m)])
dp[rabit[1]][rabit[0]]=99999999
move=[[-1, 0], [-1, -1], [-1, 1]]
def find(x, y):
    if dp[y][x]!=-1: return dp[y][x]
    res=0
    for v in move:
        mx=x+v[0]; my=y+v[1]
        if 0<=mx<m and 0<=my<n and board[my][mx]!='#':
            res=max(res, find(mx, my)+(1 if board[my][mx]=='C' else 0))
    dp[y][x]=res
    return dp[y][x]

for y in range(n):
    for x in range(m):
        find(x, y)

ans=-1
for i in hole:
    ans=max(ans, dp[i[1]][i[0]])

print(ans-99999999 if ans>=99999999 else -1)