'''
14440번
정수 수열

미완성
'''

import sys
input=sys.stdin.readline

x, y, a0, a1, n=map(int, input().split())

dp={0: [a0, 0, 0], 1:[a1, 0, 0]} #value x y
def solve(i):
    if i in dp: return dp[i]
    A=solve(i-1)
    B=solve(i-2)
    dp[i]=[(A[0]+B[0])%100, A[1]+B[1]+1, A[2]+B[2]+1]
    return dp[i]

def modPow(a, b):
    if b==0: return 1
    elif b%2==0:
        return modPow(a, b//2)*modPow(a, b//2)%100
    else:
        return a*modPow(a, b//2)*modPow(a, b//2)%100

ans=0
res=solve(n)
ans=(modPow(x, res[1])+modPow(y, res[2]))*res[0]%100

print(ans)