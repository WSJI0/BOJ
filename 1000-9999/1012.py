'''
1012번
유기농 배추
'''

testCase=int(input())

maps=[]

def check(n,m):
    if n<0

for _ in range(testCase):
    m,n,k=list(map(int,input().split()))

    for i in range(m):
        maps.append([])
        for _ in range(n):
            maps[i].append(0)
    
    for _ in range(k):
        x,y=list(map(int,input().split()))
        maps[y][x]=1
    
    for j in range(len(maps)-1):
        for k in range(len(maps[j])-1):
            if maps[j-1][k-1]==1 or maps[j+1][k-1]==1 or maps[j-1][k+1]==1 or maps[j+1][k+1]==1:
                maps[j][k]=0
    print(maps)
    