'''
13975번
파일 합치기 3
'''

import sys
import heapq
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    k=int(input())
    a=list(map(int, input().split()))
    heapq.heapify(a)
    ans=0
    while len(a)>1:
        res=heapq.heappop(a)+heapq.heappop(a)
        ans+=res
        heapq.heappush(a, res)

    print(ans)