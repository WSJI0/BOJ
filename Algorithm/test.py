import sys
input=sys.stdin.readline

def extendedGCD(a, b):
    r0=a; r1=b
    s0=1; s1=0
    t0=0; t1=1

    while r1:
        q=r0//r1
        temp=r0
        r0=r1
        r1=temp-r1*q
        temp=s0
        s0=s1
        s1=temp-s1*q
        temp=t0
        t0=t1
        t1=temp-t1*q
    return r0, s0, t0

t=int(input())
for _ in range(t):
    r, s, q=map(int, input().split())
    R, S, T=extendedGCD(r,s)
    R=(q//T)*R
    S=(q//T)*S
0