'''
2624번
동전 바꿔주기
'''

import sys
input=sys.stdin.readline

t=int(input())
k=int(input())
m={}
for _ in range(k):
    a, b=map(int, input().split())
    m[a]=b

dp={}; if 1 in m: dp[1]=1
def solve(n):
    if n in dp: return dp[n]
    for i in m.keys():
        if m[i]

print(solve(t))