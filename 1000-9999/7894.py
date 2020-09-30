'''
7894번
큰 수
'''

import sys
import math
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    m=int(input())
    ans=0
    for i in range(1, m+1):
        ans+=math.log10(i)
    print(int(ans+1))