'''
18248번
제야의 종
'''

n,m=list(map(int,input().split()))
j=[]
no=0

def check(m,j):
    for i in range(m):
        if i!=0:
            if j[i]==1 and j[i-1]==0:
                return 0
    return 1

for _ in range(n):
    j=list(map(int,input().split()))

    if check(m,j)==0:
        no=1

if no==1:
    print('NO')
else:
    print('YES')