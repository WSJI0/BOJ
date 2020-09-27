'''
2688번
줄어들지 않아
'''

import sys
input=sys.stdin.readline

dp=[0, 55]
pSum=[0,1,3,6,10,15,21,28,36,45,55]
for i in range(2, 10):
    res=0; p=dp[i-1]; j=10
    while p>0:
        if j==0: j=10
        p-=j
        res+=pSum[j]
        j-=1
    dp.append(res)

t=int(input())
for _ in range(t):
    n=int(input())
    print(dp[n])

    #1 4 13 36.4 91 208