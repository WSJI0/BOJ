'''
11066번
파일 합치기
'''

import sys
input=sys.stdin.readline
INF=987654321

def solve(l, r):
    if dp[l][r]!=INF: return dp[l][r]
    if l==r: 
        dp[l][r]=0; return 0
    if l+1==r:
        dp[l][r]=a[l]+a[r]
        return dp[l][r]
    for i in range(l, r):
        dp[l][r]=min(dp[l][r], solve(l, i)+solve(i+1, r))

    dp[l][r]+=(p[r+1]-p[l])
    return dp[l][r]

t=int(input())
for _ in range(t):
    k=int(input())
    dp=[[INF for _ in range(k+1)] for _ in range(k+1)]
    a=list(map(int, input().split()))
    p=[0]
    for i in range(k):
        p.append(p[-1]+a[i])
    print(solve(0, k-1))