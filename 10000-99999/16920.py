'''
16920번
확장 게임
'''

import sys
input=sys.stdin.readline

n, m=map(int, input().split())
s=list(map(int, input().split()))
board=[]
for _ in range(n):
    board.append(list(map(int, input().split())))

