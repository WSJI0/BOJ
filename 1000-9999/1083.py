'''
1083번
소트
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
s=int(input())

for i in range(n):
    x=0; y=0
    for j in range(i, n):
        if j-i>s: break
        if a[j]>x: 
            x=a[j]; y=j
    s-=(y-i)
    for j in range(y, i, -1): 
        a[j],a[j-1]=a[j-1],a[j]

print(*a)