'''
9375번
패션왕 신해빈
'''

import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n=int(input())
    dic={}
    for _ in range(n):
        a, b=input().rstrip().split()
        if b not in dic: dic[b]=0
        dic[b]+=1

    res=1
    for i in dic.values():
        res*=(i+1)
    print(res-1)