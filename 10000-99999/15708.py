'''
15708번
미네크래프트
'''

import sys
import heapq
input=sys.stdin.readline

n, t, p=map(int, input().split())
a=list(map(int, input().split()))

ans=0; pq=[]; sel=0; cnt=0
for i in range(min(n, t//p+1)):
    sel+=a[i]
    heapq.heappush(pq, -a[i])
    while t-i*p<sel:
        sel+=heapq.heappop(pq)
        cnt+=1
    ans=max(ans, i-cnt+1)

print(ans)