'''
7516번
알렉산드리아의 디오판토스
'''

import sys
input=sys.stdin.readline

def gcd(a, b):
    return b if a%b==0 else gcd(b, a%b)

t=int(input())
for _ in range(t):
    n=int(input())
    