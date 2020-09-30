'''
5549번
행성 탐사

미완성
'''

import sys
input=sys.stdin.readline

m, n=map(int, input().split())
k=int(input())

board=[]
for _ in range(m):
    board.append(list(input().rstrip()))

pSum=[[0 for _ in range(n+1)]]
for y in range(1, m+1):
    pSum.append([0])
    

for _ in range(k):
    sx, sy, ex, ey=map(int, input().split())

    ans=[0,0,0]
    
    print(*ans)