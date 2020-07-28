'''
19538번
루머
'''

import sys
from collections import deque
import time
input=sys.stdin.readline

n=int(input())

st=time.time()

graph={}
for i in range(1, n+1):
    graph[i]=deque()
for i in range(1, n+1):
    a=deque(map(int, input().split()))
    a.popleft()
    graph[i].extend(a)

m=int(input())
M=deque(map(int, input().split()))

def check(n):
    return 1 if n>=0.5 else 0

ans=[-1]*(n+1)
q=deque()
q.extend(M)
visited={}
cnt=0

while q:
    for _ in range(len(q)):
        node=q.popleft()
        if node not in visited:
            visited[node]=True
            ans[node]=cnt
            for i in graph[node]:
                c=0
                for j in graph[i]:
                    if ans[j]!=-1: c+=1
                if check(c/len(graph[i])) and i not in visited:
                    q.append(i)

    cnt+=1

print(*ans[1:])
print(time.time()-st)