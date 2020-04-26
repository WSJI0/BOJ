'''
2642번
전개도
'''

import sys

board=[]
dp=[[0,0,0,0,0,0]]*6

for _ in range(6):
    board.append(list(map(int,sys.stdin.readline().split())))


def check_1_1(x,y):
    global board
    try:
        match=[board[y+1][x],board[y+1][x+2],board[y][x],board[y+2][x],board[y+1][x+1],board[y+1][x+3]]
        if sum(match)==21:
            if match.index(1)%2==0:
                return match.index(1)+1
            else:
                return match.index(1)-1                      
    except:
        return False

ans=0
for y in range(6):
    for x in range(6):
        if board[y][x]!=0:
            if check_1_1(x,y):
                ans=check(x,y)
                break

print(ans)