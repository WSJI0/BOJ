'''
2146번
다리 만들기
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
board=[]
for _ in range(n):
    board.append(list(map(int, input().split())))

visited={}
cnt=-1
move=[[1,0],[0,1],[-1,0],[0,-1]]
for y in range(n):
    for x in range(n):
        if board[y][x]==1:
            q=deque()
            q.append((x,y))
            while q:
                node=q.popleft()
                if node not in visited:
                    visited[node]=True
                    board[node[1]][node[0]]=cnt
                    for m in move:
                        mx=node[0]+m[0]
                        my=node[1]+m[1]
                        if 0<=mx<n and 0<=my<n:
                            if board[my][mx]==1:
                                q.append((mx, my))
            cnt-=1

visited={}
q=deque()
for y in range(n):
    for x in range(n):
        if board[y][x]<0:
            q.append((x,y))

cnt2=0
find=False
ans=9999999
while q:
    for _ in range(len(q)):
        node=q.popleft()
        if node not in visited:
            visited[(node[0], node[1])]=True
            for m in move:
                mx=node[0]+m[0]
                my=node[1]+m[1]
                if 0<=mx<n and 0<=my<n:
                    if board[my][mx]==0:
                        board[my][mx]=board[node[1]][node[0]]
                        q.append((mx, my))
                    elif board[my][mx]<board[node[1]][node[0]]:
                        ans=min(ans, cnt2*2)
                    elif board[my][mx]>board[node[1]][node[0]]:
                        ans=min(ans, cnt2*2+1)
    cnt2+=1
if ans<=0: ans=1
print(ans)