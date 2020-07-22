'''
16939번
2×2×2 큐브
'''

import sys
import copy
input=sys.stdin.readline

def UL(cube):
    cube[4][0],cube[4][1],cube[4][2],cube[4][3]=\
    cube[4][1],cube[4][2],cube[4][3],cube[4][0]

    cube[0][0],cube[0][3],cube[1][0],cube[1][3],\
    cube[2][0],cube[2][3],cube[3][0],cube[3][3]=\
    cube[1][0],cube[1][3],cube[2][0],cube[2][3],\
    cube[3][0],cube[3][3],cube[0][0],cube[0][3]

def UR(cube):
    cube[4][1],cube[4][2],cube[4][3],cube[4][0]=\
    cube[4][0],cube[4][1],cube[4][2],cube[4][3]

    cube[1][0],cube[1][3],cube[2][0],cube[2][3],\
    cube[3][0],cube[3][3],cube[0][0],cube[0][3]=\
    cube[0][0],cube[0][3],cube[1][0],cube[1][3],\
    cube[2][0],cube[2][3],cube[3][0],cube[3][3]

def DL(cube):
    cube[5][0],cube[5][1],cube[5][2],cube[5][3]=\
    cube[5][3],cube[5][0],cube[5][1],cube[5][2]

    cube[0][1],cube[0][2],cube[1][1],cube[1][2],\
    cube[2][1],cube[2][2],cube[3][1],cube[3][2]=\
    cube[1][1],cube[1][2],cube[2][1],cube[2][2],\
    cube[3][1],cube[3][2],cube[0][1],cube[0][2]

def DR(cube):
    cube[5][3],cube[5][0],cube[5][1],cube[5][2]=\
    cube[5][0],cube[5][1],cube[5][2],cube[5][3]

    cube[1][1],cube[1][2],cube[2][1],cube[2][2],\
    cube[3][1],cube[3][2],cube[0][1],cube[0][2]=\
    cube[0][1],cube[0][2],cube[1][1],cube[1][2],\
    cube[2][1],cube[2][2],cube[3][1],cube[3][2]

def FL(cube):
    cube[1][0],cube[1][1],cube[1][2],cube[1][3]=\
    cube[1][3],cube[1][0],cube[1][1],cube[1][2]

    cube[0][2],cube[0][3],cube[5][3],cube[5][0],\
    cube[2][0],cube[2][1],cube[4][1],cube[4][2]=\
    cube[4][1],cube[4][2],cube[0][2],cube[0][3],\
    cube[5][3],cube[5][0],cube[2][0],cube[2][1]

def FR(cube):
    cube[1][3],cube[1][0],cube[1][1],cube[1][2]=\
    cube[1][0],cube[1][1],cube[1][2],cube[1][3]

    cube[4][1],cube[4][2],cube[0][2],cube[0][3],\
    cube[5][3],cube[5][0],cube[2][0],cube[2][1]=\
    cube[0][2],cube[0][3],cube[5][3],cube[5][0],\
    cube[2][0],cube[2][1],cube[4][1],cube[4][2]

def BL(cube):
    cube[3][0],cube[3][1],cube[3][2],cube[3][3]=\
    cube[3][1],cube[3][2],cube[3][3],cube[3][0]

    cube[2][2],cube[2][3],cube[4][3],cube[4][0],\
    cube[0][0],cube[0][1],cube[5][1],cube[5][2]=\
    cube[5][1],cube[5][2],cube[2][3],cube[2][2],\
    cube[4][3],cube[4][0],cube[0][0],cube[0][1]

def BR(cube):
    cube[3][1],cube[3][2],cube[3][3],cube[3][0]=\
    cube[3][0],cube[3][1],cube[3][2],cube[3][3]

    cube[5][1],cube[5][2],cube[2][3],cube[2][2],\
    cube[4][3],cube[4][0],cube[0][0],cube[0][1]=\
    cube[2][2],cube[2][3],cube[4][3],cube[4][0],\
    cube[0][0],cube[0][1],cube[5][1],cube[5][2]

def LU(cube):
    cube[0][0],cube[0][1],cube[0][2],cube[0][3]=\
    cube[0][3],cube[0][0],cube[0][1],cube[0][2]

    cube[4][0],cube[4][1],cube[1][0],cube[1][1],\
    cube[5][0],cube[5][1],cube[3][2],cube[3][3]=\
    cube[1][0],cube[1][1],cube[5][0],cube[5][1],\
    cube[3][2],cube[3][3],cube[4][0],cube[4][1]

def LD(cube):
    cube[0][3],cube[0][0],cube[0][1],cube[0][2]=\
    cube[0][0],cube[0][1],cube[0][2],cube[0][3]

    cube[1][0],cube[1][1],cube[5][0],cube[5][1],\
    cube[3][2],cube[3][3],cube[4][0],cube[4][1]=\
    cube[4][0],cube[4][1],cube[1][0],cube[1][1],\
    cube[5][0],cube[5][1],cube[3][2],cube[3][3]

def RU(cube):
    cube[2][0],cube[2][1],cube[2][2],cube[2][3]=\
    cube[2][1],cube[2][2],cube[2][3],cube[2][0]

    cube[4][2],cube[4][3],cube[1][2],cube[1][3],\
    cube[5][2],cube[5][3],cube[3][0],cube[3][1]=\
    cube[1][2],cube[1][3],cube[5][2],cube[5][3],\
    cube[3][0],cube[3][1],cube[4][2],cube[4][3]

def RD(cube):
    cube[2][1],cube[2][2],cube[2][3],cube[2][0]=\
    cube[2][0],cube[2][1],cube[2][2],cube[2][3]

    cube[1][2],cube[1][3],cube[5][2],cube[5][3],\
    cube[3][0],cube[3][1],cube[4][2],cube[4][3]=\
    cube[4][2],cube[4][3],cube[1][2],cube[1][3],\
    cube[5][2],cube[5][3],cube[3][0],cube[3][1]

def check(cube):
    if cube[0][0]==cube[0][1]==cube[0][2]==cube[0][3] and\
    cube[1][0]==cube[1][1]==cube[1][2]==cube[1][3] and\
    cube[2][0]==cube[2][1]==cube[2][2]==cube[2][3] and\
    cube[3][0]==cube[3][1]==cube[3][2]==cube[3][3] and\
    cube[4][0]==cube[4][1]==cube[4][2]==cube[4][3] and\
    cube[5][0]==cube[5][1]==cube[5][2]==cube[5][3]:
        return True
    return False

def swap(val):
    val[1],val[2],val[3]=val[2],val[3],val[1]
    return val

li=list(map(int, input().rstrip().split()))
c=[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
c[4]=swap(li[0:4])
c[0]=swap(li[12:16])
c[1]=swap(li[4:8])
c[2]=swap(li[16:20])
c[3]=swap(li[20:24])
c[5]=swap(li[8:12])

spin=['UL(cube)','UR(cube)','DL(cube)','DR(cube)','FL(cube)','FR(cube)','BL(cube)','BR(cube)','LU(cube)','LD(cube)','RU(cube)','RD(cube)']

ans=0
for s in spin:
    cube=copy.deepcopy(c)
    exec(s)
    if check(cube):
        ans=1
        break
print(ans)