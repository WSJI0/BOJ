'''
9663번
N-Queen
'''

board=[]

n=int(input())
for _ in range(n): board.append([0]*n)

def check(board, x, y):
    global n
    for i in range(y):
        if board[i][x]:
            return False
        if (y-i-1>=0 and x+i+1<n) and board[y-i-1][x+i+1]:
            return False
        if (y-i-1>=0 and x-i-1>=0) and board[y-i-1][x-i-1]:
            if y-i-1<0 or x-i-1<0: continue
            return False

    return True
        

cnt=0
visited={}
def backT(cur):
    global board, visited
    global cnt

    if cur==n:
        cnt+=1
        return
    
    for x in range(n):
        if not check(board, x, cur): continue
        board[cur][x]=1
        backT(cur+1)
        board[cur][x]=0
backT(0)
print(cnt)