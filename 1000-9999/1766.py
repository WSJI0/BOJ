'''
1766번
문제집
'''

import sys
import heapq
from copy import deepcopy
input=sys.stdin.readline

n, m=map(int, input().split())
dic={}
dic2={}
for i in range(1, n+1):
    dic[i]=[]
    dic2[i]=[]

for _ in range(m):
    a, b=map(int, input().split())
    heapq.heappush(dic[b], -a)

def pr(d):
    d2=deepcopy(d)
    a=[]
    while d2:
        a.append(dic2[-heapq.heappop(d2)])
    while a:
        pr(a.pop())
    if d:
        print(-heapq.heappop(d), end=' ')

for i in range(1, n+1):
    if not dic[i]: 
        print(i, end=' ')
        pr(dic2[i])
    else:
        heapq.heappush(dic2[-dic[i][0]], -i)