'''
1525번
퍼즐
'''

import sys
from collections import deque
input=sys.stdin.readline

board=0; z=0
for i in range(3):
    a=list(map(int, input().split()))
    for j in range(3):
        if a[j]==0: 
            a[j]=9
            z=(i*3)+j
        board=board*10+a[j]

change=[1, -1, 3, -3]
visited={}; ans=-1

def move(b, l, l2):
    l=8-l; l2=8-l2
    tmp=b//pow(10, l)%10
    tmp2=b//pow(10, l2)%10

    b-=pow(10, l)*tmp
    b+=pow(10, l)*tmp2
    b-=pow(10, l2)*tmp2
    b+=pow(10, l2)*tmp

    return b

q=deque()
q.append((0, board, z))
while q and ans==-1:
    node=q.popleft()
    cnt, board2, l=node
    if board2==123456789: ans=cnt
    for i in range(4):
        L=l+change[i]
        if((L<0 or L>8) or (l%3==2 and i==0) or (l%3==0 and i==1)): continue
        b=move(board2, l, L)
        if b not in visited:
            q.append((cnt+1, b, L))
            visited[b]=True

print(ans)