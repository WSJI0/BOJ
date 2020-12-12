'''
2613번
숫자구슬
'''

import sys
input=sys.stdin.readline

n, m=map(int, input().split())
a=list(map(int, input().split()))

dp={}
p=[0]*n; p[0]=a[0]
for i in range(1, n):
    p[i]=p[i-1]+a[i]

print(p)