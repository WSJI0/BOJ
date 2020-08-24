'''
1201번
NMK
'''

import sys
input=sys.stdin.readline

n, m, k=map(int, input().split())
if m+k-1>n or n>m*k: print(-1)
else:
    ans=[]
    a=[i for i in range(1, n+1)]