'''
11651번
좌표 정렬하기 2
'''

n=int(input())

coor=[]
for _ in range(n):
    a,b=map(int,input().split())
    coor.append([b,a])

coor.sort()
for i in range(n):
    print(coor[i][1], coor[i][0])