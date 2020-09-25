'''
1915번
가장 큰 정사각형
'''

import sys
input=sys.stdin.readline

board=[]
dp=[]
n, m=map(int, input().split())
for _ in range(n):
    board.append(list(map(int, input().rstrip())))

dp.append(board[0])
ans=max(dp[0])
for i in range(1, n):
    a=[board[i][0]]
    for j in range(1, m):
        if board[i][j]==1:
            if board[i-1][j]==1 and board[i-1][j-1]==1 and board[i][j-1]==1:
                a.append(min(dp[i-1][j], dp[i-1][j-1], a[j-1])+1)
            else: a.append(1)
        else: a.append(0)
    dp.append(a)
    ans=max(ans, max(a))

print(ans*ans)