'''
17090번
미로 탈출하기
'''

import sys
sys.setrecursionlimit(10**9)
input=sys.stdin.readline

n, m=map(int, input().split())
board=[]; dp=[]
for _ in range(n):
    board.append(list(input().rstrip()))
    dp.append([-1]*m)

def solve(y, x):
    global dp, visited
    if (y, x) in visited:
        return 0

    visited[(y, x)]=True
    if dp[y][x]!=-1:
        return dp[y][x]
 
    if board[y][x]=='U':
        if y==0: dp[y][x]=1
        else: dp[y][x]=solve(y-1, x)
    elif board[y][x]=='D':
        if y==n-1: dp[y][x]=1
        else: dp[y][x]=solve(y+1, x)
    elif board[y][x]=='L':
        if x==0: dp[y][x]=1
        else: dp[y][x]=solve(y, x-1)
    elif board[y][x]=='R':
        if x==m-1: dp[y][x]=1
        else: dp[y][x]=solve(y, x+1)

    return dp[y][x]

for y in range(n):
    for x in range(m):
        visited={}
        solve(y, x)

ans=0
for y in range(n):
    ans+=dp[y].count(1)

print(ans)