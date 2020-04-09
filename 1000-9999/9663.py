'''
9663번
N-Queen
'''

n=int(input())
board=[]

for _ in range(n):
    board.append([0]*n)

def check(a,b):
    global board
    if 1 in board[a]:
        return False
    for i in range(n):
        if board[i][b]==1:
            return False
            break
    for s1 in range(1,min(a,b)+1):
        if board[a-s1][b-s1]==1:
            return False
            break

    for s2 in range(1,min(n-1-a,n-1-b)+1):
        if board[a+s2][b+s2]==1:
            return False
            break

    for s3 in range(1,min(n-1-a,b)+1):
        if board[a+s3][b-s3]==1:
            return False
            break

    for s4 in range(1,min(a,n-1-b)+1):
        if board[a-s4][b+s4]==1:
            return False
            break
 
    return True

for i in range(n):
    for j in range(n):
        print(i,j,check(i,j))
        if (i!=0 and j!=0) and (i!=0 and j!=1) and (i!=0 and j!=2) and (i!=0 and j!=3):
            if check(i,j):
                board[i][j]=1
                break

for k in board:
    print(k)