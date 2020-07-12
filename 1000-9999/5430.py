'''
5430번
AC
'''

import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    p=list(input().rstrip())
    n=int(input())
    x=input().rstrip()[1:-1].split(',')
    
    if x==['']: x=[]

    crash=False
    cnt=0
    toPop=0
    l=0
    r=len(x)
    for i in p:
        if i=='R':
            toPop=(0 if toPop!=0 else 1)
            cnt+=1
        elif i=='D':
            if l>=r:
                crash=True
                break
            else:
                if toPop==0: l+=1
                else: r-=1

    if not crash:
        if cnt%2==0:
            print("["+','.join(x[l:r])+"]")
        else:
            print("["+','.join(list(reversed(x[l:r])))+"]")
    else:
        print("error")