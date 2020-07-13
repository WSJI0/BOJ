'''
5014번
스타트링크
'''

import sys
from collections import deque
input=sys.stdin.readline

f, s, g, u, d=map(int, input().split())

visited={}
q=deque()
q.append(s)

cnt=0
while q:
    for i in range(len(q)):
        n=q.popleft()
        if n not in visited:
            visited[n]=True
            if n+u<=f: q.append(n+u)
            if n-d>0: q.append(n-d)
    if g in visited: break
    cnt+=1

if g in visited:
    print(cnt)
else:
    print("use the stairs")