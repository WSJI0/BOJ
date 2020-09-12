'''
7662번
이중 우선순위 큐
'''

import sys
from collections import deque
import bisect
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    q=deque()
    qd={}
    k=int(input())
    for _ in range(k):
        op, val=input().rstrip().split()
        val=int(val)
        if op=='D':
            if q and val==1:
                qd[q[-1]]-=1
                if qd[q[-1]]==0: q.pop()
            elif q and val==-1: 
                qd[q[0]]-=1
                if qd[q[0]]==0: q.popleft()

        else:           
            if val not in qd: 
                qd[val]=0
                bisect.insort_left(q, val)
            qd[val]+=1
            
    if q: print(q[-1], q[0])
    else: print("EMPTY")