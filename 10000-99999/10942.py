'''
10942번
팰린드롬?
'''

import sys
sys.setrecursionlimit(10**6)
input=sys.stdin.readline
print=sys.stdout.write

n=int(input())
a=list(map(int, input().split()))
dp=[[-1 for _ in range(2001)] for _ in range(2001)]

def solve(l, r):
    if l==r: dp[l][r]=1; return 1
    elif l>r: return 1
    if dp[l][r]!=-1: return dp[l][r]

    if solve(l+1, r-1)==1 and a[l]==a[r]: dp[l][r]=1
    else: dp[l][r]=0
    return dp[l][r]

for i in range(n):
    for j in range(n):
        solve(i, j)

m=int(input())
for _ in range(m):
    s, e=map(int, input().split())
    if dp[s-1][e-1]==1: print('1\n')
    else: print('0\n')