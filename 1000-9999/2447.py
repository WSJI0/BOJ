'''
2447번
별찍기 - 10
'''

import sys

n=int(input())

def check(x,y):
    while(x>0):
        if x%3==1 and y%3==1:
            print(' ', end='')
            return 0
        x=x//3
        y=y//3
    print('*', end='')


for y in range(n):
    for x in range(n):
        check(x,y)
    print()
