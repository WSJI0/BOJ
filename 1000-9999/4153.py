'''
4153번
직각삼각형
'''


coor=[1,1,1]
while(coor!=[0,0,0]):
    ans=''
    i,j,k=list(map(int,input().split()))
    coor[0]=i
    coor[1]=j
    coor[2]=k

    if max(coor)**2-coor[coor.index(max(coor))-1]**2-coor[coor.index(max(coor))-2]**2==0:
        ans='right'
    else:
        ans='wrong'

    if coor!=[0,0,0]:
        print(ans)