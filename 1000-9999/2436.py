'''
2436번
공약수
'''

import sys
input=sys.stdin.readline

g, l=map(int, input().split())

d=[]
for i in range(1, int(l**0.5)+1):
    if l%i==0: 
        d.append(i)
        if l//i!=i: d.append(l//i)

def GCD(a, b):
    return b if a%b==0 else GCD(b, a%b)

def LCM(a,b):
    return a*b/GCD(a, b)

ans=[999999999999, 99999999999]
for i in range(len(d)):
    for j in range(i+1, len(d)):
        if GCD(d[i], d[j])==g and LCM(d[i], d[j])==l:
            if d[i]+d[j]<sum(ans):
                ans=[d[i], d[j]]
if g==l:
    print(g,l)
else:
    print(*list(sorted(ans)))