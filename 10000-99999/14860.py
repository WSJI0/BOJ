'''
14860번
GCD 곱
'''

import sys
input=sys.stdin.readline

def modPow(a, n, l):
    if n==0: return 1
    res=modPow(a*a%l, n//2, l)
    if n&1: res=res*a%l
    return res

n, m=map(int, input().split())
ans=1
for i in range(n):
    res=0
    for j in range()