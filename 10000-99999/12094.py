'''
12094번
2048 (Hard)
'''

import sys
import copy
from collections import deque
input=sys.stdin.readline

n=int(input())

b=[]; ori=0
for _ in range(n):
    b.append(list(map(int, input().split())))
    ori=max(ori, max(b[-1]))

def move(board, direction, maxVal):
    global n
    mV=maxVal
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
                        if mV<board[i][J-1]: mV=board[i][J-1]
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
                        if mV<board[i][J+1]: mV=board[i][J+1]
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
                        if mV<board[J-1][i]: mV=board[J-1][i]
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
                        if mV<board[J+1][i]: mV=board[J+1][i]
                        board[J][i]=0
                        mix=J+1
    return mV

ans=0
def solve(N, l, m): #깊이, 게임판
    global ans
    if N==10:
        if m>ans: ans=m
        return
    if ans//pow(2,(9-N))>m: return
    for v in range(1, 5):
        l2=copy.deepcopy(l)
        mV=move(l2, v, m)
        if l2!=l: solve(N+1, l2, mV) 

solve(0, b, ori)
print(ans)