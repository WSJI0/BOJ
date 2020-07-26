'''
2239번
스도쿠
'''

import sys
input=sys.stdin.readline

board=[]
for _ in range(9):
    board.append(list(map(int, input().rstrip())))

blank=[]
for y in range(9):
    for x in range(9):
        if board[y][x]==0:
            blank.append([x,y])

def backT(n, cur, cnt):
    global blank, board, ans
    if cur==cnt:
        for y in board:
            for x in y:
                print(x, end='')
            print()
        exit()
    
    num=list(range(1,10))
    can={0:False, 1:True, 2:True, 3:True, 4:True, 5:True, 6:True, 7:True, 8:True, 9:True}
    for i in range(9):
        can[board[i][blank[cur][0]]]=False     
        can[board[blank[cur][1]][i]]=False
    
    y=blank[cur][1]//3*3
    x=blank[cur][0]//3*3
    can[board[y][x]]=False
    can[board[y+1][x]]=False
    can[board[y+2][x]]=False
    can[board[y][x+1]]=False
    can[board[y+1][x+1]]=False
    can[board[y+2][x+1]]=False
    can[board[y][x+2]]=False
    can[board[y+1][x+2]]=False
    can[board[y+2][x+2]]=False

    for i in range(1,10):
        if can[i]:
            board[blank[cur][1]][blank[cur][0]]=i
            backT(i,cur+1,cnt)
            board[blank[cur][1]][blank[cur][0]]=0

backT(0, 0, len(blank))