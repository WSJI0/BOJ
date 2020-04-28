'''
11414번
LCM
'''

import sys
import math

a,b=map(int,sys.stdin.readline().split())
if a>b: a,b=b,a

def GCD(x,y):
    if y==0:
        return x
    else:
        return GCD(y, x%y)

def LCM(X,Y):
    return (X*Y)//GCD(X,Y)

p=[]
for i in range(1,int((b-a)**0.5)+1):
    if (b-a)%i==0:
        if i in p:
            break
        else:
            p.extend([i,(b-a)//i])
p.sort()
MIN=99999999999999999999999999
MINN=0
for j in range(1,len(p)):
    n=math.ceil(a/p[j])*p[j]-a
    if n==0:
        n=(1+math.ceil(a/p[j]))*p[j]-a
    if MIN>LCM(a+n,b+n):
        MIN=LCM(a+n,b+n)
        MINN=n
    elif MIN==LCM(a+n, b+n):
        if MINN>n:
            MINN=n

if a==b:
    print(1)
else:
    if MINN!=0:
        print(MINN)
    else:
        print(1)