'''
1034번
램프
'''

import sys

n, m=map(int, sys.stdin.readline().split())

board=[]
for i in range(n):
    a=sys.stdin.readline().rstrip()
    board.append([int(i) for i in a])

k=int(sys.stdin.readline())

switch=[0]*len(board[0])

for j in board:
    for l in range(len(j)):
        if j[l]==0:
            switch[l]+=1
            
