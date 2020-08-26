'''
14888번
연산자 끼워넣기
'''

import sys
import copy
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
b=list(map(int, input().split()))

ansMax=-9999999999; ansMin=9999999999
def solve(p, b):
    global ansMax, ansMin, a
    if b==[0,0,0,0]:
        res=a[0]
        for i in range(1, len(a)):
            if p[i-1]=='//':
                if res<0:
                    res=abs(res)
                    res=-eval(str(res)+p[i-1]+str(a[i]))
                else:
                    res=eval(str(res)+p[i-1]+str(a[i]))
            else:
                res=eval(str(res)+p[i-1]+str(a[i]))
        ansMax=max(ansMax, res)
        ansMin=min(ansMin, res)
        return
    
    B=copy.deepcopy(b)
    if B[0]>0:
        B[0]-=1
        P=copy.deepcopy(p)
        P.append('+')
        solve(P, B)
    B=copy.deepcopy(b)
    if B[1]>0:
        B[1]-=1
        P=copy.deepcopy(p)
        P.append('-')
        solve(P, B)
    B=copy.deepcopy(b)
    if B[2]>0:
        B[2]-=1
        P=copy.deepcopy(p)
        P.append('*')
        solve(P, B)
    B=copy.deepcopy(b)
    if B[3]>0:
        B[3]-=1
        P=copy.deepcopy(p)
        P.append('//')
        solve(P, B)

solve([], b)
print(ansMax)
print(ansMin)