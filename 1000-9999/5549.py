'''
5549번
행성 탐사

미완성
'''

import sys
input=sys.stdin.readline

m, n=map(int, input().split())
k=int(input())

board=[]
for _ in range(m):
    board.append(list(input().rstrip()))

def op(n):
    return int(n)-1

for _ in range(k):
    sx, sy, ex, ey=map(op, input().split())

    ans=[0,0,0]
    for y in range(sy, ey+1):
        for x in range(sx, ex+1):
            if board[x][y]=='J': ans[0]+=1
            elif board[x][y]=='O': ans[1]+=1
            else: ans[2]+=1
    print(*ans)