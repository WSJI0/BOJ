'''
1520번
내리막 길
'''

import sys
input=sys.stdin.readline

m, n=map(int, input().split())
board=[]
dp=[]
for _  in range(m):
    board.append(list(map(int, input().split())))
    dp.append([-1 for _ in range(n)])
dp[0][0]=1

def route(y, x):
    global dp
    if dp[y][x]!=-1: return dp[y][x]
    res=0
    if y>0 and board[y][x]<board[y-1][x]:
        res+=route(y-1, x)
    if y<m-1 and board[y][x]<board[y+1][x]:
        res+=route(y+1, x)
    if x>0 and board[y][x]<board[y][x-1]:
        res+=route(y, x-1)
    if x<n-1 and board[y][x]<board[y][x+1]:
        res+=route(y, x+1)
    dp[y][x]=res
    return res

for y in range(m):
    for x in range(n):
        route(y, x)

print(dp[m-1][n-1])