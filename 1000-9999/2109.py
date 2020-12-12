'''
2109번
순회 강연
'''

import sys
import heapq
input=sys.stdin.readline

n=int(input())
p=[]
for _ in range(n):
    p.append(list(map(int, input().split())))

p.sort(key=lambda k:k[1])

s=[]; ans=0
for i in range(10000, 0, -1):
    while p and p[-1][1]>=i:
        heapq.heappush(s, -(p.pop()[0]))
    if s:
        ans-=heapq.heappop(s)

print(ans)