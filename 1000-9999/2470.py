'''
2470번
두 용액
'''

import sys

n=int(sys.stdin.readline())

a=list(map(int, sys.stdin.readline().split()))
a.sort()

#-99 -2 -1 4 98
l=0
r=n-1
MIN=9999999999999999
ans=[0,0]
while(l<r):
    if abs(a[l]+a[r])<MIN:
        MIN=abs(a[l]+a[r])
        ans=[a[l], a[r]]

print(*ans)