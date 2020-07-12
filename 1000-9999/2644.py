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
visited=[]
while queue:
    n=queue.pop(0)
    if n not in visited:
        visited.append(n)
        queue.extend(graph[n])
        print("NNNNNN",n)