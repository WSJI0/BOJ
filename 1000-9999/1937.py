'''
1937번
욕심쟁이 판다
'''

import sys
sys.setrecursionlimit(10**9)
input=sys.stdin.readline

n=int(input())
board=[]
for _ in range(n):
    board.append(list(map(int, input().split())))

dp=[[0]*n for _ in range(n)]
def solve(y, x):
    global dp
    if dp[y][x]==0: dp[y][x]=1
    else: return dp[y][x]
    res=0
    if y>0 and board[y-1][x]<board[y][x]:
        res=max(res, solve(y-1, x))
    if y<n-1 and board[y+1][x]<board[y][x]:
        res=max(res, solve(y+1, x))
    if x>0 and board[y][x-1]<board[y][x]:
        res=max(res, solve(y, x-1))
    if x<n-1 and board[y][x+1]<board[y][x]:
        res=max(res, solve(y, x+1))
    dp[y][x]=res+1
    return dp[y][x]
    
for y in range(n):
    for x in range(n):
        solve(y, x)

ans=0
for i in dp:
    ans=max(ans, max(i))
print(ans)