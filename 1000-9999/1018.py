'''
1018번
체스판 다시 칠하기
'''

n,m=map(int,input().split())

board=[]

def check(li):
    mod1=0
    mod2=0
    for i in range(8):
        for j in range(8):
            if (i%2==0 and j%2==0) or (i%2==1 and j%2==1):
                if li[i][j]=='W':
                    mod1+=1
            if (i%2==0 and j%2==1) or (i%2==1 and j%2==0):
                if li[i][j]=='B':
                    mod1+=1

    for i in range(8):
        for j in range(8):
            if (i%2==0 and j%2==0) or (i%2==1 and j%2==1):
                if li[i][j]=='B':
                    mod2+=1
            if (i%2==0 and j%2==1) or (i%2==1 and j%2==0):
                if li[i][j]=='W':
                    mod2+=1
    return min(mod1, mod2)


for _ in range(n):
    row=list(input())
    board.append(row)

mi=2500
for k in range(n-7):
    for l in range(m-7):
        c=check([board2[l:(8+l)] for board2 in board[k:(8+k)]])
        if c<mi:
            mi=c

print(mi)