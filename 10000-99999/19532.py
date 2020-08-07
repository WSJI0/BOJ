'''
19532번
수학은 비대면강의입니다
'''

import sys
input=sys.stdin.readline

a,b,c,d,e,f=map(int, input().split())

for y in range(-999, 1000):
    for x in range(-999, 1000):
        if a*x+b*y==c and d*x+e*y==f:
            print(x, y)
            break