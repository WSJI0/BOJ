'''
1963번
소수 경로
'''

import sys
from collections import deque
input=sys.stdin.readline

num=[i for i in range(2, 10000)]
pNum=[0 for _ in range(10000)]
for i in num:
    for j in num:
        if i==j: continue
        if j%i==0:
            num.remove(j)
for i in num: pNum[i]=1

t=int(input())
for _ in range(t):
    a, b=map(int, input().split())

    visited={}
    q=deque()
    q.append(a)
    cnt=0
    find=False
    while q:
        for _ in range(len(q)):
            node=q.popleft()
            if node not in visited:
                visited[node]=True
                if node==b: 
                    find=True
                    break
                for m in range(4):
                    for r in range(0, 10):
                        if m==3 and r==0: continue
                        s=node
                        s-=(s%(10**(m+1))-s%(10**m))
                        s+=(10**m)*r
                        if pNum[s]==1:
                            q.append(s)
        if find: break
        cnt+=1
    print(cnt)