'''
2644번
촌수계산
'''

import sys
input=sys.stdin.readline

n=int(input())
a, b=map(int, input().split())
m=int(input())

graph={}
for i in range(1, n+1):
    graph[i]=[]

for _ in range(m):
    x, y=map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

queue=[a]
visited={}
cnt=0
find=False
while queue:
    for i in range(len(queue)):
        n=queue.pop(0)
        if n not in visited:
            if n==b: 
                find=True
                break
            visited[n]=True
            queue.extend(graph[n])
    if find: break
    cnt+=1
if find:
    print(cnt)
else:
    print(-1)