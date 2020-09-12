'''
1781번
컵라면
'''

import sys
import heapq
input=sys.stdin.readline

n=int(input())
a=[]
for _ in range(n):
    a.append(list(map(int, input().split())))
a.sort()

h=[]
for i in range(n):
    heapq.heappush(h, a[i][1])
    while a[i][0]<len(h): heapq.heappop(h)

print(sum(h))