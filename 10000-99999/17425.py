'''
17425번
약수의 합
'''

import sys
input=sys.stdin.readline

dp=[0]
f=[1 for _ in range(1000001)]
for i in range(2, 1000001):
    for j in range(1, 1000000//i+1):
        f[i*j]+=i

for i in range(1, 1000001):
    dp.append(dp[i-1]+f[i])

t=int(input())
for _ in range(t):
    n=int(input())
    print(dp[n])