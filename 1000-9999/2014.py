'''
2014번
소수의 곱
'''

import sys
import heapq
input=sys.stdin.readline

k, n=map(int, input().split())
a=list(map(int, input().split()))
h=[1]
dic={}
m=0

for _ in range(n):
    p=heapq.heappop(h)
    for i in range(k):
        if (len(h)>n and p*a[i]>m) or p*a[i] in dic: continue
        dic[p*a[i]]=True
        heapq.heappush(h, p*a[i])
        m=max(m, p*a[i])

print(h[0])