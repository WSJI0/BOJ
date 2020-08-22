'''
8980번
택배

미완성
'''

import sys
input=sys.stdin.readline

n, c=map(int, input().split())
m=int(input())

l=[]
for _ in range(m):
    s, t, b=map(int, input().split())
    l.append([s, t, b])

l.sort()

ans=0
for i in range(m):
    l[i]