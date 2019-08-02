'''
1002번
터렛
'''

testCase=int(input())
for i in range(testCase):
    coor=input().split() #x1 y1 r1 x2 y2 r2
    
    distance=(int(coor[0])-int(coor[3]))**2+(int(coor[1])-int(coor[4]))**2
    sum=(int(coor[2])+int(coor[5]))**2
    min=(int(coor[2])-int(coor[5]))**2
    
    if distance==0:
        if int(coor[2])==int(coor[5]):
            print(-1)
        else:
            print(0)
    else:
        if distance<sum and distance>min:
            print(2)
        elif distance==sum or distance==min:
            print(1)
        else:
            print(0)
