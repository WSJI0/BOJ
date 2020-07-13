'''
2206번
벽 부수고 이동하기
'''

import sys
from collections import deque
input=sys.stdin.readline

N, M=map(int, input().split())

board=[]
for _ in range(N):
    board.append(list(map(int, input().rstrip())))

q=deque()
q.append((0,0,1))
visited={}
cnt=0
find=False
move=[[1,0], [0,1], [-1,0], [0,-1]]

while q:
    for _ in range(len(q)):
        n=q.popleft()
        if n not in visited:
            visited[n]=True
            if n[0]==M-1 and n[1]==N-1:
                find=True
                break

            for m in move:
                if 0<=n[0]+m[0]<M and 0<=n[1]+m[1]<N:
                    if board[n[1]+m[1]][n[0]+m[0]]==0:
                        q.append((n[0]+m[0], n[1]+m[1], n[2]))
                    else:
                        if n[2]==1:
                            q.append((n[0]+m[0], n[1]+m[1], 0))
    if find: break
    cnt+=1


if find:
    print(cnt+1)
else:
    print(-1)