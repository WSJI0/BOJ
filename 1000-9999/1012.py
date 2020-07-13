'''
1012번
유기농 배추
'''

import sys
input=sys.stdin.readline

def dfs(graph, node):
    visited=[]
    stack=[node]

    while stack:
        n=stack.pop()
        if n not in visited:
            visited.append(n)
            stack.extend(graph[n])
    return visited

t=int(input())

for _ in range(t):
    m, n, k=map(int, input().split())
    graph={}
    for i in range(k):
        x, y=map(int, input().split())
        if (x,y) not in graph:
            graph[(x,y)]=[]
        if x>0 and (x-1, y) in graph:
            graph[(x,y)].append((x-1, y))
            graph[(x-1,y)].append((x,y))
        if y>0 and (x, y-1) in graph:
            graph[(x,y)].append((x,y-1))
            graph[(x,y-1)].append((x,y))
        if x<m-1 and (x+1, y) in graph:
            graph[(x,y)].append((x+1,y))
            graph[(x+1,y)].append((x,y))
        if y<n-1 and (x,y+1) in graph:
            graph[(x,y)].append((x,y+1))
            graph[(x,y+1)].append((x,y))

    visited=[]        
    cnt=0
    for y in range(n):
        for x in range(m):
            if (x, y) in graph and (x, y) not in visited:
                stack=[(x,y)]
                cnt+=1
                while stack:
                    n=stack.pop()
                    if n not in visited:
                        visited.append(n)
                        stack.extend(graph[n])

    print(cnt)