'''
2447번
별찍기 - 10
'''

import sys

n=int(input())

def check(x,y):
    while(x>0):
        if x%3==1 and y%3==1:
            sys.stdout.write(' ')
            return 0
        x=x//3
        y=y//3
    sys.stdout.write('*')


for y in range(n):
    for x in range(n):
        check(x,y)
    sys.stdout.write('\n')
