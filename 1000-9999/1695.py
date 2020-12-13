'''
1695번
팰린드롬 만들기
'''

import sys
sys.setrecursionlimit(10**6)
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))

dp=[[-1 for _ in range(n)] for _ in range(n)]

def solve(l, r):
    if l>r: return 0
    if dp[l][r]!=-1: return dp[l][r]
    if a[l]==a[r]: dp[l][r]=solve(l+1, r-1)
    else: dp[l][r]=min(solve(l+1, r), solve(l, r-1))+1
    return dp[l][r]

print(solve(0, n-1))