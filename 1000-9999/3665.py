'''
3665번
최종 순위

미완성
'''

import sys
from collections import deque
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n=int(input())
    t=list(map(int, input().split()))

    s=[0]*n
    for i in range(n):
        s[t[i]]=i

    m=int(input())
    graph={}
    for _ in range(m):
        a, b=map(int, input().split())
        if s[a]>s[b]:
            if a not in graph: graph[a]=[]
            graph[a].append(b)
        else:
            if b not in graph: graph[b]=[]
            graph[b].append(a)
        