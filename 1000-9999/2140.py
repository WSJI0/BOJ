'''
2140번
지뢰찾기
'''

import sys
input=sys.stdin.readline

n=int(input())

board=[]
for _ in range(n):
    board.append(list(input().rstrip()))

move=[[1,0],[0,1],[1,1],[-1,0],[0,-1],[-1,-1],[1,-1],[-1,1]]
for y in range(n):
    for x in range(n):
        if board[y][x]=='#':
            no=False
            for m in move:
                mx=m[0]+x
                my=m[1]+y
                if 0<=mx<n and 0<=my<n:
                    if board[my][mx]=='0':
                        no=True
            if not no:
                board[y][x]='*'
                for m in move:
                    mx=m[0]+x
                    my=m[1]+y
                    if 0<=mx<n and 0<=my<n:
                        if board[my][mx]!='#' and board[my][mx]!='*':
                            board[my][mx]=str(int(board[my][mx])-1)

ans=0
for i in board:
    ans+=i.count('*')
print(ans)