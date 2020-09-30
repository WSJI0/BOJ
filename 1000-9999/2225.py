'''
2225번
합분해
'''

import sys
input=sys.stdin.readline

n, k=map(int, input().split())

dp=[1 for _ in range(n+1)]
for _ in range(k-1):
    a=[]
    for j in range(n+1):
        a.append(sum(dp[:j+1]))
    dp=a
    print(dp)

print(dp[n]%1000000000)