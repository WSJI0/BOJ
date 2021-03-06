'''
12100번
2048 (Easy)
'''

import sys
import copy
from collections import deque
input=sys.stdin.readline

n=int(input())

board=[]
for _ in range(n):
    board.append(list(map(int, input().split())))

def move(board, direction):
    global n
    if direction==1: #우->좌
        for i in range(n):
            mix=-1
            for j in range(1, n):
                if board[i][j]!=0:
                    J=j
                    while J>0 and board[i][J-1]==0: J-=1
                    if j!=J:
                        board[i][J]=board[i][j]
                        board[i][j]=0
                    if board[i][J-1]==board[i][J] and J-1>mix:
                        board[i][J-1]*=2
                        board[i][J]=0
                        mix=J-1
    elif direction==2: #좌->우
        for i in range(n):
            mix=n
            for j in range(n-2, -1, -1):
                if board[i][j]!=0:
                    J=j
                    while J<n-1 and board[i][J+1]==0: J+=1
                    if j!=J:
                        board[i][J]=board[i][j]
                        board[i][j]=0
                    if J+1<mix and board[i][J+1]==board[i][J]:
                        board[i][J+1]*=2
                        board[i][J]=0
                        mix=J+1
    elif direction==3: #하->상
        for i in range(n):
            mix=-1
            for j in range(1, n):
                if board[j][i]!=0:
                    J=j
                    while J>0 and board[J-1][i]==0: J-=1
                    if j!=J:
                        board[J][i]=board[j][i]
                        board[j][i]=0
                    if board[J-1][i]==board[J][i] and J-1>mix:
                        board[J-1][i]*=2
                        board[J][i]=0
                        mix=J-1
    elif direction==4: #상->하
        for i in range(n):
            mix=n
            for j in range(n-2, -1, -1):
                if board[j][i]!=0:
                    J=j
                    while J<n-1 and board[J+1][i]==0: J+=1
                    if j!=J:
                        board[J][i]=board[j][i]
                        board[j][i]=0
                    if J+1<mix and board[J+1][i]==board[J][i]:
                        board[J+1][i]*=2
                        board[J][i]=0
                        mix=J+1
    return board

ans=0
def solve(N, l):
    global board, ans
    if N==4:
        board2=copy.deepcopy(board)
        for i in l:
            move(board2, i)
        val=0
        for i in board2: 
            val=max(val, max(i))
        ans=max(ans, val)
        return

    solve(N+1, l+[1])
    solve(N+1, l+[2])
    solve(N+1, l+[3])
    solve(N+1, l+[4])

solve(0, [1])
solve(0, [2])
solve(0, [3])
solve(0, [4])

print(ans)