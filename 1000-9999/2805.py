'''
2805번
나무 자르기
'''

import sys
input=sys.stdin.readline

n, m=map(int, input().split())
a=list(map(int, input().split()))

l=0
r=max(a)

while(l<=r):
    tree=0
    mid=(l+r)//2
    for i in range(n):
        tree+=max(a[i]-mid, 0)
    if tree>=m:
        l=mid+1
    else:
        r=mid-1
print(r)