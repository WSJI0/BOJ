'''
12101번
1, 2, 3 더하기 2
'''

import sys
input=sys.stdin.readline

n, k=map(int, input().split())

dp=[[1], [2], [3]]
ans=[]
for i in range(n):
    a=[]
    for j in range(len(dp)):
        if sum(dp[j])+1<=n: a.append(dp[j]+[1])
        if sum(dp[j])+2<=n: a.append(dp[j]+[2])
        if sum(dp[j])+3<=n: a.append(dp[j]+[3])
        if sum(dp[j])==n: 
            ans.append(list(map(str, dp[j])))
    dp=a

ans.sort()

if k<=len(ans):
    print('+'.join(ans[k-1]))
else:
    print(-1)