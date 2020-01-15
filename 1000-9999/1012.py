'''
1012번
유기농 배추
'''

testCase=int(input())

maps=[]

for _ in range(testCase):
    m,n,k=list(map(int,input().split()))

    for i in range(m):
        maps.append([])
        for j in range(n):
            maps[i].append(0)
    
    for _ in range(k):
        x,y=list(map(int,input().split()))
        maps[y][x]=1
    print(maps)