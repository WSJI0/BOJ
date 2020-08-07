'''
5373번
큐빙

  0
1 2 3 4
  5

0 1 2
3 4 5
6 7 8

'''

import sys
input=sys.stdin.readline

def rotate(cube, i):
    cube[i][0],cube[i][1],cube[i][2],cube[i][3],\
    cube[i][4],cube[i][5],cube[i][6],cube[i][7],\
    cube[i][8]=cube[i][2],cube[i][5],cube[i][8],\
    cube[i][1],cube[i][4],cube[i][7],cube[i][0],\
    cube[i][3],cube[i][6]

def U(cube):
    rotate(cube, 0)
    cube[2][0],cube[2][1],cube[2][2],cube[3][0],\
    cube[3][1],cube[3][2],cube[4][0],cube[4][1],\
    cube[4][2],cube[1][0],cube[1][1],cube[1][2]=\
    cube[1][0],cube[1][1],cube[1][2],cube[2][0],\
    cube[2][1],cube[2][2],cube[3][0],cube[3][1],\
    cube[3][2],cube[4][0],cube[4][1],cube[4][2]

def D(cube):
    rotate(cube, 5)
    cube[2][6],cube[2][7],cube[2][8],cube[3][6],\
    cube[3][7],cube[3][8],cube[4][6],cube[4][7],\
    cube[4][8],cube[1][6],cube[1][7],cube[1][8]=\
    cube[3][6],cube[3][7],cube[3][8],cube[4][6],\
    cube[4][7],cube[4][8],cube[1][6],cube[1][7],\
    cube[1][8],cube[2][6],cube[2][7],cube[2][8]

def F(cube):
    rotate(cube, 2)
    cube[0][6],cube[0][7],cube[0][8],cube[3][0],\
    cube[3][3],cube[3][6],cube[5][2],cube[5][1],\
    cube[5][0],cube[1][8],cube[1][5],cube[1][2]=\
    cube[3][0],cube[3][3],cube[3][6],cube[5][2],\
    cube[5][1],cube[5][0],cube[1][8],cube[1][5],\
    cube[1][2],cube[0][8],cube[0][5],cube[0][2]

def B(cube):
    rotate(cube, 4)
    cube[0][0],cube[0][1],cube[0][2],cube[3][2],\
    cube[3][5],cube[3][8],cube[5][6],cube[5][7],\
    cube[5][8],cube[1][0],cube[1][3],cube[1][6]=\
    cube[1][6],cube[1][3],cube[1][0],cube[0][0],\
    cube[0][1],cube[0][2],cube[3][8],cube[3][5],\
    cube[3][2],cube[5][6],cube[5][7],cube[5][8]

def L(cube):
    rotate(cube, 1)
    cube[0][0],cube[0][3],cube[0][6],cube[2][0],\
    cube[2][3],cube[2][6],cube[5][0],cube[5][3],\
    cube[5][6],cube[4][2],cube[4][5],cube[4][8]=\
    cube[2][0],cube[2][3],cube[2][6],cube[5][0],\
    cube[5][3],cube[5][6],cube[4][8],cube[4][5],\
    cube[4][2],cube[0][6],cube[0][3],cube[0][0]

def R(cube):
    rotate(cube, 3)
    cube[0][2],cube[0][5],cube[0][8],cube[2][2],\
    cube[2][5],cube[2][8],cube[5][2],cube[5][5],\
    cube[5][8],cube[4][0],cube[4][3],cube[4][6]=\
    cube[4][6],cube[4][3],cube[4][0],cube[0][2],\
    cube[0][5],cube[0][8],cube[2][2],cube[2][5],\
    cube[2][8],cube[5][8],cube[5][5],cube[5][2]


t=int(input())

for _  in range(t):
    cube=[['w']*9, ['g']*9, ['r']*9, ['b']*9, ['o']*9, ['y']*9]
    n=int(input())
    spin=list(input().split())
    for s in spin:
        if '-' in s:
            eval(s[:1]+'(cube)')
        elif '+' in s:
            for _ in range(3):
                eval(s[:1]+'(cube)')
    
    for i in range(3):
        for j in range(3):
            print(cube[0][i*3+j], end='')
        print()
    
    #print(cube)