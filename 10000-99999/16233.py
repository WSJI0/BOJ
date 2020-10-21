'''
16233번
수학 문제
'''

import sys
input=sys.stdin.readline

t=int(input())

cnt=0
for n in range(1, t+1):
    ans=-1; cnt+=1
    for x in range(1, 10000):
        if n+sum(list(map(int, str(x))))==x:
            ans=x; break
    if ans!=-1:
        #print(n, "ANS : ",ans)
        pass
    elif n%9==0:
        print(n," is passed", cnt//9)
        cnt=0