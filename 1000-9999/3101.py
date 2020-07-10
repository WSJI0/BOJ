'''
3101번
토끼의 이동

미완성
'''

import sys
input=sys.stdin.readline

n, k=map(int, input().split())
s=list(input().rstrip())

coor=[0,0]
m=0
for i in s:
    if i=='U': coor[1]-=1
    elif i=='D': coor[1]+=1
    elif i=='L': coor[0]-=1
    elif i=='R': coor[0]+=1

    if coor[0]%2==1:

    coor[1]