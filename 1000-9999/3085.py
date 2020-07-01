'''
3085번
사탕 게임

미완성
'''

import sys

n=int(sys.stdin.readline())

board=[]
yMax=0
xMax=0
for i in range(n):
    board.append([])
    board[i]=list(sys.stdin.readline().rstrip())

for y in range(n):
    for x in range(n):
        for i in range(4):
            if i==0 and y!=0:
                if board[y][x]!=board[y-1][x]:
                    board[y][x], board[y-1][x]=board[y-1][x], board[y][x]
            elif i==1 and y!=n-1:
                if board[y][x]!=board[y+1][x]:
                    board[y][x], board[y+1][x]=board[y+1][x], board[y][x]
            elif i==2 and x!=0:
                if board[y][x]!=board[y][x-1]:
                    board[y][x], board[y][x-1]=board[y][x-1], board[y][x]
            elif i==3 and x!=n-1:
                if board[y][x]!=board[y][x+1]:
                    board[y][x], board[y][x+1]=board[y][x+1], board[y][x]

print(max(max(board)))