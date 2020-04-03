'''
11650번
좌표 정렬하기
'''

n=int(input())

coor=[]
for _ in range(n):
    coor.append(list(map(int,input().split())))

coor.sort()
for i in range(n):
    print(coor[i][0], coor[i][1])