'''
2831번
댄스 파티
'''

import sys
import heapq
input=sys.stdin.readline

n=int(input())
m=list(map(int, input().split()))
f=list(map(int, input().split()))

male=[[], []]
female=[[], []]
for i in range(n):
    if m[i]>0: heapq.heappush(male[0], m[i])
    else: heapq.heappush(male[1], -m[i])
    if f[i]>0: heapq.heappush(female[0], f[i])
    else: heapq.heappush(female[1], -f[i])

ans=0
while True:
    if not male[0] or not female[1]: break
    if male[0][0]<female[1][0]:
        ans+=1
        heapq.heappop(male[0])
    heapq.heappop(female[1])
while True:
    if not male[1] or not female[0]: break
    if male[1][0]>female[0][0]:
        ans+=1
        heapq.heappop(female[0])
    heapq.heappop(male[1])

print(ans)