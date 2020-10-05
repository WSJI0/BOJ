'''
1202번
보석 도둑
'''

import sys
import heapq
input=sys.stdin.readline

n, k=map(int, input().split())
jewel=[]; bag=[]
for _ in range(n): jewel.append(list(map(int, input().split())))
for _ in range(k): bag.append(int(input()))

jewel.sort()
bag.sort()
ans=0; j=0; p=[]
for i in range(k):
    res=0; resIdx=0
    while j<n and bag[i]>=jewel[j][0]:
        heapq.heappush(p, -jewel[j][1])
        j+=1
    if p: ans+=abs(heapq.heappop(p))

print(ans)