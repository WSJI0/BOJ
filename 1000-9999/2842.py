'''
2842번
최대공약수
'''

import sys
from math import gcd
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
m=int(input())
b=list(map(int, input().split()))

A=1; B=1
for i in a:
    A*=i
for i in b:
    B*=i

g=gcd(A, B)
if len(str(g))>9:
    print(str(g)[-9:])
else:
    print(g)