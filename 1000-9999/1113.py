'''
1113번
수영장 만들기

미완성
'''

import sys
from collections import deque
input=sys.stdin.readline

n, m=map(int, input().split())
pool=[]
for _ in range(n):
    pool.append(list(map(int, input().rstrip())))

move=[[1,0],[0,1],[-1,0],[0,-1]]
visited={}
cnt=0
for y in range(n):
    for x in range(m):
        q=deque()
        if (x,y) not in visited:
            q.append((x,y))
            cnt+=1
        while q:
            node=q.pop()
            if node not in visited:
                visited[node]=True
                for v in move:
                    mx=v[0]+node[0]
                    my=v[1]+node[1]
                    if 1<=mx<m-1 and 1<=my<n-1:
                        if pool[my][mx]<pool[y][x]:
                            q.append((mx,my))
print(cnt)
