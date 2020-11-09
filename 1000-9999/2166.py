'''
2166번
다각형의 면적
'''

import sys
import math
input=sys.stdin.readline

n=int(input())
coor=[]
for _ in range(n):
    coor.append(list(map(int, input().split())))

ans=0
for i in range(n-1):
    ans+=(coor[i][0]+coor[i+1][0])*(coor[i][1]-coor[i+1][1])
ans+=(coor[n-1][0]+coor[0][0])*(coor[n-1][1]-coor[0][1])

print("%.1f" % math.fabs(ans/2))