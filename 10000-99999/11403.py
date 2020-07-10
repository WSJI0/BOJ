'''
11403번
경로 찾기
'''

import sys
input=sys.stdin.readline

board=[]
n=int(input())
for _ in range(n):
    board.append(list(map(int, input().split())))

maxCnt=0
for i in range(100, 0, -1):
    graph={}
    for y in range(n):
        for x in range(n):
            if board[y][x]>=i:
                if (x,y) not in graph:
                    graph[(x,y)]=[]
                if x>0 and (x-1, y) in graph:
                    graph[(x,y)].append((x-1, y))
                    graph[(x-1,y)].append((x,y))
                if y>0 and (x, y-1) in graph:
                    graph[(x,y)].append((x,y-1))
                    graph[(x,y-1)].append((x,y))
                if x<n-1 and (x+1, y) in graph:
                    graph[(x,y)].append((x+1,y))
                    graph[(x+1,y)].append((x,y))
                if y<n-1 and (x,y+1) in graph:
                    graph[(x,y)].append((x,y+1))
                    graph[(x,y+1)].append((x,y))

    cnt=0
    visited=[]
    for y in range(n):
        for x in range(n):
            if (x, y) in graph and (x, y) not in visited:
                stack=[(x,y)]
                cnt+=1
                while stack:
                    m=stack.pop()
                    if m not in visited:
                        visited.append(m)
                        stack.extend(graph[m])


    maxCnt=max(maxCnt, cnt)
print(maxCnt)