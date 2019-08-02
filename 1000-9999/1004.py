'''
1004번
어린 왕자
'''

planet=[]
passNum=0

testCase=int(input())
for i in range(testCase):
    coor=input().split()
    p=int(input())

    for i2 in range(p):
        pl=input().split()
        planet.append(pl)

    for i3 in planet:
        if int(i3[2])>((int(coor[0])-int(i3[0]))**2+(int(coor[1])-int(i3[1]))**2)**0.5 and not(int(i3[2])>((int(coor[2])-int(i3[0]))**2+(int(coor[3])-int(i3[1]))**2)**0.5):
            passNum+=1
        if int(i3[2])>((int(coor[2])-int(i3[0]))**2+(int(coor[3])-int(i3[1]))**2)**0.5 and not(int(i3[2])>((int(coor[0])-int(i3[0]))**2+(int(coor[1])-int(i3[1]))**2)**0.5):
            passNum+=1
    print(passNum)
    passNum=0
    planet=[]
