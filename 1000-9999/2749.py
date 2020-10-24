'''
2749번
피보나치 수 3

미완성
'''

import sys
input=sys.stdin.readline

dp={0:0, 1:1, 2:1, 3:2, 4:3}
mod=1000000
def fibo(n):
    if n in dp: return dp[n]
    dp[n]=((fibo(n//2)%mod)*(fibo(n//2)%mod))%mod
    return dp[n]

n=int(input())
print(fibo(n)%mod)
print(dp)