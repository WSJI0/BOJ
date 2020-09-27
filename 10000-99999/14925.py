'''
14925번
목장 건설하기
'''

import sys
input=sys.stdin.readline

m, n=map(int, input().split())
board=[]
dp=[]
for _ in range(m):
    board.append(list(map(int, input().split())))
    dp.append([0 for _ in range(n)])

ans=0
for y in range(m):
    for x in range(n):
        if y>0 and x>0:
            if board[y][x]==0:
                if board[y-1][x]==0 and board[y-1][x-1]==0 and board[y][x-1]==0:
                    dp[y][x]=(min(dp[y-1][x], dp[y-1][x-1], dp[y][x-1])+1)
                else:
                    dp[y][x]=(0 if board[y][x]>0 else 1)
            else:
                dp[y][x]=0
        else:
            dp[y][x]=(0 if board[y][x]>0 else 1)
    ans=max(ans, max(dp[y]))

print(ans)