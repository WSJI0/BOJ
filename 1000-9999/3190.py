'''
3190번
뱀

미완성
'''

import sys
input=sys.stdin.readline

n=int(input())
board=[]
for _ in range(n): board.append([0]*n)
board[0][0]=1
head=[0, 0]; tail=[0, 0]

k=int(input())
for _ in range(k):
    x, y=map(int, input().split())
    board[y-1][x-1]=1
