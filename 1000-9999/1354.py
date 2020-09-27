'''
1354번
무한 수열 2
'''

import sys
input=sys.stdin.readline

n, p, q, x, y=map(int, input().split())

dp={}
def solve(i):
    if i<=0: return 1
    if i in dp: return dp[i]
    dp[i]=solve(i//p-x)+solve(i//q-y)
    return dp[i]

print(solve(n))