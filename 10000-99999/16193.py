'''
16193번
차이를 최대로 2
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
a.sort()
a=deque(a)
res=deque()
res.append(a.pop())
ans=0
for i in range(n-1):
    res1=abs(a[-1]-res[-1])
    res2=abs(a[-1]-res[0])
    res3=abs(a[0]-res[-1])
    res4=abs(a[0]-res[0])
    m=max(res1, res2, res3, res4)
    if m==res1:
        ans+=res1
        res.append(a.pop())
    elif m==res2:
        ans+=res2
        res.appendleft(a.pop())
    elif m==res3:
        ans+=res3
        res.append(a.popleft())
    else:
        ans+=res4
        res.appendleft(a.popleft())
print(ans)