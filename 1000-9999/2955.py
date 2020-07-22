'''
2955번
스도쿠 풀기

미완성
'''

import sys
input=sys.stdin.readline

board=[]
for _ in range(9):
    board.append(list(input().rstrip()))

for y in range(9):
    for x in range(9):
        if board[y][x]=='.':
            for i in range(1, 10):
                if board[y-y%3][x-x%3]==i: continue
                elif board[y-y%3+1][x-x%3]==i: continue
                elif board[y-y%3+2][x-x%3]==i: continue
                elif board[y-y%3][x-x%3+1]==i: continue
                elif board[y-y%3+1][x-x%3+1]==i: continue
                elif board[y-y%3+2][x-x%3+1]==i: continue
                elif board[y-y%3][x-x%3+2]==i: continue
                elif board[y-y%3+1][x-x%3+2]==i: continue
                elif board[y-y%3+2][x-x%3+2]==i: continue

                no=False
                for j in range(9):
                    if board[j][x]==i: no=True
                    if board[y][j]==i: no=True
                if no: continue

                board[y][x]=i
                break

for i in board:
    print(*i)