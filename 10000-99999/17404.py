'''
17404번
RGB거리 2
'''

import sys
input=sys.stdin.readline

n=int(input())
home=[]
for _ in range(n):
    home.append(list(map(int, input().split())))

ans=99999999999
for c in range(3):
    dp=[99999999999 for _ in range(3)]
    dp[c]=home[0][c]

    for i in range(1, n):
        a=[]
        a.append(min(dp[1]+home[i][0], dp[2]+home[i][0]))
        a.append(min(dp[0]+home[i][1], dp[2]+home[i][1]))
        a.append(min(dp[0]+home[i][2], dp[1]+home[i][2]))
        dp=a

    for i in range(3):
        if i!=c: ans=min(ans, dp[i])

print(ans)