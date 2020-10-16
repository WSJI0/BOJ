'''
12850번
본대 산책2

미완성
'''

import sys
input=sys.stdin.readline

def modPow(a, n, l):
    if n==0: return 1
    res=modPow(a*a%l, n//2, l)
    if n&1: res=res*a%l
    return res

n=int(input())
print(modPow(2, n, 1000000007))