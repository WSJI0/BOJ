'''
10422번
괄호
'''

import sys
input=sys.stdin.readline

dp={0: 1, 2: 1}
def bracket(n):
    if n%2==1: return 0
    if n in dp: return dp[n]
    res=0
    for i in range(2, n+1, 2):
        res+=bracket(i-2)*bracket(n-i)
    dp[n]=res%1000000007
    return dp[n]

t=int(input())
for _ in range(t):
    n=int(input())
    print(bracket(n))