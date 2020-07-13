'''
2206번
벽 부수고 이동하기
'''

import sys
input=sys.stdin.readline

n, m=map(int, input().split())

board=[]
for _ in range(board):
    board.append(list(input().rstrip()))

