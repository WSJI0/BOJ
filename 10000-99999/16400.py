'''
16400번
소수 화폐

미완성
'''

import sys
input=sys.stdin.readline

dp={0: 0, 1: 0, 2: 1}

def isPrime(n):
    for i in range(2, int(n**0.5)+1):
        if n%i==0: return False
    return True

for i in range(3, 40000, 2):
    if isPrime(i): dp[i]=1

def p(n):
    if n in dp: return n
    res=0
    for i in range(n+1):
        res+=p(i)*p(n-i)
    dp[n]=res
    return dp[n]

n=int(input())
print(p(n))