'''
11066번
파일 합치기

미완성
'''

import sys
input=sys.stdin.readline

def solve(l, r):
    if dp[l][r]!=-1: return dp[l][r]
    if l==r: return a[l]
    if l+1==r:
        dp[l][r]=a[l]+a[r]
        return dp[l][r]
    res=9999999999999
    for i in range(1, r-l):
        res=min(res, solve(l+i, r)+solve(l, r-i))
    dp[l][r]=res
    return dp[l][r]*2

t=int(input())
for _ in range(t):
    k=int(input())
    dp=[[-1 for _ in range(k)] for _ in range(k)]
    a=list(map(int, input().split()))
    print(solve(0, k-1))