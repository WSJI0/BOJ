'''
9972번
Rubik's Cube Solver
'''

import sys
input=sys.stdin.readline

def rotate(cube, i):
    cube[i][0],cube[i][1],cube[i][2],cube[i][3],\
    cube[i][4],cube[i][5],cube[i][6],cube[i][7],\
    cube[i][8]=cube[i][2],cube[i][5],cube[i][8],\
    cube[i][1],cube[i][4],cube[i][7],cube[i][0],\
    cube[i][3],cube[i][6]

def top(cube):
    rotate(cube, 0)
    cube[2][0],cube[2][1],cube[2][2],cube[3][0],\
    cube[3][1],cube[3][2],cube[4][0],cube[4][1],\
    cube[4][2],cube[1][0],cube[1][1],cube[1][2]=\
    cube[1][0],cube[1][1],cube[1][2],cube[2][0],\
    cube[2][1],cube[2][2],cube[3][0],cube[3][1],\
    cube[3][2],cube[4][0],cube[4][1],cube[4][2]

def bottom(cube):
    rotate(cube, 5)
    cube[2][6],cube[2][7],cube[2][8],cube[3][6],\
    cube[3][7],cube[3][8],cube[4][6],cube[4][7],\
    cube[4][8],cube[1][6],cube[1][7],cube[1][8]=\
    cube[3][6],cube[3][7],cube[3][8],cube[4][6],\
    cube[4][7],cube[4][8],cube[1][6],cube[1][7],\
    cube[1][8],cube[2][6],cube[2][7],cube[2][8]

def front(cube):
    rotate(cube, 2)
    cube[0][6],cube[0][7],cube[0][8],cube[3][0],\
    cube[3][3],cube[3][6],cube[5][2],cube[5][1],\
    cube[5][0],cube[1][8],cube[1][5],cube[1][2]=\
    cube[3][0],cube[3][3],cube[3][6],cube[5][2],\
    cube[5][1],cube[5][0],cube[1][8],cube[1][5],\
    cube[1][2],cube[0][6],cube[0][7],cube[0][8]

def back(cube):
    rotate(cube, 4)
    cube[0][0],cube[0][1],cube[0][2],cube[3][2],\
    cube[3][5],cube[3][8],cube[5][6],cube[5][7],\
    cube[5][8],cube[1][0],cube[1][3],cube[1][6]=\
    cube[1][6],cube[1][3],cube[1][0],cube[0][0],\
    cube[0][1],cube[0][2],cube[3][8],cube[3][5],\
    cube[3][2],cube[5][6],cube[5][7],cube[5][8]

def left(cube):
    rotate(cube, 1)
    cube[0][0],cube[0][3],cube[0][6],cube[2][0],\
    cube[2][3],cube[2][6],cube[5][0],cube[5][3],\
    cube[5][6],cube[4][2],cube[4][5],cube[4][8]=\
    cube[2][0],cube[2][3],cube[2][6],cube[5][0],\
    cube[5][3],cube[5][6],cube[4][8],cube[4][5],\
    cube[4][2],cube[0][6],cube[0][3],cube[0][0]

def right(cube):
    rotate(cube, 3)
    cube[0][2],cube[0][5],cube[0][8],cube[2][2],\
    cube[2][5],cube[2][8],cube[5][2],cube[5][5],\
    cube[5][8],cube[4][0],cube[4][3],cube[4][6]=\
    cube[4][6],cube[4][3],cube[4][0],cube[0][2],\
    cube[0][5],cube[0][8],cube[2][2],cube[2][5],\
    cube[2][8],cube[5][8],cube[5][5],cube[5][2]

def solved(cube):
    for i in range(6):
        if cube[i].count(cube[i][0])!=9:
            return False
    return True

while True:
    i=input().rstrip()
    if i=="START":
        cube=[[],[],[],[],[],[]]
        for _ in range(3):
            line=input().rstrip().split()
            for j in line: cube[0].append(j)
        for _ in range(3):
            line=input().rstrip().split()
            for j in range(12): cube[j//3+1].append(line[j])
        for _ in range(3):
            line=input().rstrip().split()
            for j in line: cube[5].append(j)

        while True:
            i2=input().rstrip().split()
            if i2==['END']: break
            if i2[1]=='left':
                eval(i2[0]+'(cube)')
            else: 
                for _ in range(3):
                    eval(i2[0]+'(cube)')
        print("Yes" if solved(cube) else "No")

    elif i=="ENDOFINPUT": break