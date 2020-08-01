'''
11660번
구간 합 구하기 5
'''

import sys
input=sys.stdin.readline

n, m=map(int, input().split())
board=[]
for _ in range(n):
    board.append(list(map(int, input().split())))

pSum=[[0]*(n+1)]
for y in range(n):
    pSum.append([0])
    for x in range(n):
        pSum[y+1].append(pSum[y+1][x]+board[y][x]+pSum[y][x+1]-pSum[y][x])

for _ in range(m):
    y1, x1, y2, x2=map(int, input().split())
    print(pSum[y2][x2]+pSum[y1-1][x1-1]-pSum[y1-1][x2]-pSum[y2][x1-1])