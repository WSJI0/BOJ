'''
17425번
약수의 합
'''

import sys
input=sys.stdin.readline

dp=[0]
for i in range(1, 1000001):
    res=0
    for j in range(1, int(i**0.5)+1):
        if i%j==0:
            res+=j
            if j!=i//j: res+=i//j
    dp.append(dp[i-1]+res)

t=int(input())
for _ in range(t):
    n=int(input())
    print(dp[n])