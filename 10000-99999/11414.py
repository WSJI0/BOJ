'''
11414번
LCM
'''

import sys
a,b=map(int,sys.stdin.readline().split())

def GCD(x,y):
    if y==0:
        return x
    else:
        return GCD(y, x%y)

def LCM(x2, y2):
    return (x2*y2)//GCD(x2,y2)

if a==b:
    print(1)
else:
    MIN=999999999999999999
    MININDEX=0
    for i in range(b//a,-1,-1):
        n=b-(i*a)
        if n!=0:
            if LCM(a+n, b+n)<MIN:
                MIN=LCM(a+n, b+n)
                MININDEX=n
    if MININDEX!=0:
        print(MININDEX)
    else:
        print(GCD(a,b))