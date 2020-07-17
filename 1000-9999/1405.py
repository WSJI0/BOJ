'''
1405번
미친 로봇

미완성
'''

import sys
from collections import deque
input=sys.stdin.readline

N, e, w, s, n=map(int, input().split())
e/=100; w/=100; s/=100; n/=100

visited={}
q=deque()
q.extend([('e', 1), ('w', 1), ('s' ,1), ('n', 1)])
move=['e', 'w', 's', 'n']
rate={
    'e':e, 'w':w, 's':s, 'n':n
}
cnt=0

while q:
    node=q.pop()
    for m in move:
        if m!=node[0]:
            q.append((m, node[1]*rate[m]))
    cnt+=1
    if cnt==N: break
print(q)