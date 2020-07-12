'''
9465번
스티커

미완성
'''

import sys
input=sys.stdin.readline

t=int(input())

for _ in range(t):
    n=int(input())
    sticker=[]
    for i in range(n):
        sticker.append(list(map(int, input().split()))) 

    dp=[[0,0,0]*(n+1)]
    for i in range(n):
        dp[i+1][0]=max(dp[i+1][0], dp[i][0], dp[i][1], dp[i][2])
        dp[i+1][1]=max(dp[i+1][1], dp[i][1], dp[i][0], dp[i][2])+sticker[0][i]
        dp[i+1][2]=max(dp[i+1][2], dp[i][1], dp[i][0], dp[i][1])+sticker[1][i]

    print(max(dp[n][0], dp[n][1], dp[n][2]))