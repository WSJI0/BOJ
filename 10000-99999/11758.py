'''
11758번
CCW
'''

import sys
input=sys.stdin.readline

p=[]
for _ in range(3):
    p.append(list(map(int, input().split())))

ccw=(p[1][0]-p[0][0])*(p[2][1]-p[0][1])-(p[1][1]-p[0][1])*(p[2][0]-p[0][0])
if ccw>0: print(1)
elif ccw==0: print(0)
else: print(-1)