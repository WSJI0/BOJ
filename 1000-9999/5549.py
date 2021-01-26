'''
5549번
행성 탐사

미완성
'''

import sys
input=sys.stdin.readline
print=sys.stdout.write

m, n=map(int, input().split())
k=int(input())

board=[]; area={'J':0, 'O':1, 'I':2};
for _ in range(m):
    l=list(input().rstrip())
    board.append([])
    for i in range(len(l)):
        l2=[0, 0, 0]; l2[area[l[i]]]=1
        board[-1].append(l2)

cnt=[[[0, 0, 0] for _ in range(n)] for _ in range(m)]

for a in range(3):
    for y in range(m):
        for x in range(n):
            for i in range(y+1):
                for j in range(x+1):
                    cnt[y][x][a]+=board[i][j][a]

def solve(b, a, d, c):
    res=[]; a-=1; b-=1; c-=1; d-=1
    for i in range(3):
        r=cnt[d][c][i]
        if b-1>=0 and a-1>=0: r+=cnt[b-1][a-1][i]
        if a>=0: r-=cnt[d][a-1][i]
        if b>=0: r-=cnt[b-1][c][i]
        res.append(abs(r))
    return res

for _ in range(k):
    a, b, c, d=map(int, input().split())
    for i in solve(a, b, c, d):
        print(str(i)+' ')
    print('\n')