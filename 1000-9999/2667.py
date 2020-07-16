'''
2667번
단지번호붙이기
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())

board=[]
for _ in range(n):
    board.append(list(map(int, input().rstrip())))
q=deque()
visited={}
cnt=0
move=[[1,0],[0,1],[-1,0],[0,-1]]
ans=[]
for y in range(n):
    for x in range(n):
        if board[y][x]==1:
            cnt+=1
            ans.append(0)
            q.append((x,y))
        while q:
            node=q.pop()
            if node not in visited:
                visited[node]=True
                board[node[1]][node[0]]=0
                ans[-1]+=1
                for m in move:
                    if 0<=node[0]+m[0]<n and 0<=node[1]+m[1]<n:
                        if board[node[1]+m[1]][node[0]+m[0]]==1:
                            q.append((node[0]+m[0], node[1]+m[1]))

print(cnt)
ans.sort()
for i in ans:
    print(i)