'''
1188번
음식 평론가
'''

import sys
input=sys.stdin.readline

n, m=map(int, input().split())

def gcd(a, b):
    return b if a%b==0 else gcd(b, a%b)
print(m-gcd(n,m))