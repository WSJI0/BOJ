'''
3955번
캔디 분배
'''

import sys
input=sys.stdin.readline

def gcd(a, b):
    return (gcd(b, a%b) if b else a)

def extendedGcd(a, b):
    tmpA=a
    t1=0
    t2=1
    while(b!=0):
        r=a%b
        t=t1-(a//b)*t2
        a=b
        b=r
        t1=t2
        t2=t
        
    if t1<0: t1+=tmpA*(abs(t1)//tmpA+1)
    return t1


t=int(input())

for _ in range(t):
    k, c=map(int, input().split())
    
    if c==1:
        if k+1>1000000000:
            print("IMPOSSIBLE")
        else:
            print(k+1)
    elif k==1:
        print(1)
    elif gcd(k,c)!=1:
        print("IMPOSSIBLE")
    elif extendedGcd(k,c)>1000000000:
        print("IMPOSSIBLE")
    else:
        print(extendedGcd(k,c))