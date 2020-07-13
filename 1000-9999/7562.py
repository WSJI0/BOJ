'''
7562번
나이트의 이동
'''

import sys
input=sys.stdin.readline
from collections import deque

t=int(input())

graph={}
move=[[1,-2], [-1,-2], [1,2], [-1,2], [2,-1], [2,1], [-2,-1], [-2,1]]

for _ in range(t):
    l=int(input())
    sx, sy=map(int, input().split())
    ex, ey=map(int, input().split())

    queue=deque()
    queue.append((sx, sy))
    visited={}
    cnt=0
    find=False
    while queue:
        for _ in range(len(queue)):
            n=queue.popleft()
            if n not in visited:
                visited[n]=True
                for m in move:
                    if 0<=n[0]+m[0]<l and 0<=n[1]+m[1]<l:
                        queue.append((n[0]+m[0], n[1]+m[1]))
            if n==(ex, ey):
                find=True
                break
        if find: break
        cnt+=1
    print(cnt)