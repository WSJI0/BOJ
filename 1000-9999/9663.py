'''
9663번
N-Queen
'''

board=[]

n=int(input())
for _ in range(n): board.append([0]*n)

def check(board, x, y):
    for i in range(len(board)):
        if board[y][i]==1:
            return False
        elif board[i][x]==1:
            return False
    for i in range(-min(x,y), min(n-x,n-y)):
        if board[y+i][x+i]==1:
            return False
    for i in range(-min(x,n-y), min(n-x,y)):
        if board[y-i-1][x+i]==1:
            return False

    return True
        

cnt=0
def backT(cur):
    global cnt

    if cur==n:
        cnt+=1
        return
    
    for y in range(n):
        for x in range(n):
            if not check(board, x, y): continue
            board[y][x]=1
            backT(cur+1)
            board[y][x]=0
backT(0)
print(cnt)