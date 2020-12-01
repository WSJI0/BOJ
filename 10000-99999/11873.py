'''
11873번
최대 직사각형

미완성
'''

import sys
input=sys.stdin.readline

while True:
    board=[]
    dp=[]
    n, m=map(int, input().split())
    if n==m==0: break
    for _ in range(n):
        board.append(list(map(int, input().rstrip().split())))

    for i in range(len(board[0])):
        dp.append([board[0][i], board[0][i]])
    ans=0
    for i in range(1, n):
        a=[[board[i][0], board[i][0]]]
        for j in range(1, m):
            if board[i][j]==1:
                if board[i-1][j]==1 and board[i-1][j-1]==1 and board[i][j-1]==1:
                    a.append([max(dp[i-1][j-1][0], a[j-1][0])+1, max(dp[i-1][j][1], dp[i-1][j-1][1])+1])
                else: a.append([1, 1])
            else: a.append([0, 0])
        dp.append(a)
        res=0
        for j in range(len(a)):
            res=max(res, a[i][0]*a[i][1])
        ans=max(ans, res)

    print(ans*ans)