'''
12100번
2048 (Easy)
'''

import sys
input=sys.stdin.readline

n=int(input())

board=[]
for _ in range(n):
    board.append(list(map(int, input().split())))

dp=[board]
for _ in range(5):
    a=[]
    for i in dp:
        if 