'''
1103번
게임
'''

import sys
input=sys.stdin.readline

def inth(k):
    if k=='H': return 0
    return int(k)

n, m=map(int, input().split())
board=[]
dp=[]
for _ in range(n):
    board.append(list(map(inth, input().rstrip())))
    dp.append([-2]*m)

def solve(y, x):
    global dp, visited
    if (y, x) in visited and visited[(y, x)]:
        print(-1)
        sys.exit()
    if board[y][x]==0: 
        dp[y][x]=0
        return 0
    if dp[y][x]!=-2: return dp[y][x]
    
    visited[(y, x)]=True
    X=board[y][x]
    res=0
    if x+X<m: res=max(res, solve(y, x+X))
    if x-X>=0: res=max(res, solve(y, x-X))
    if y+X<n: res=max(res, solve(y+X, x))
    if y-X>=0: res=max(res, solve(y-X, x))
    dp[y][x]=res+1

    visited[(y, x)]=False
    return dp[y][x]

visited={}
print(solve(0, 0))