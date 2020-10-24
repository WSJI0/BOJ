'''
19577번
수학은 재밌어
'''

import sys
input=sys.stdin.readline

def phi(n):
    res=n
    for i in range(2, int(n**0.5)+1):
        if n%i==0:
            while n%i==0:
                n//=i
            res-=res//i
    if n>1:
        res-=res//n
    return res

n=int(input())
ans=-1
res=phi(n)
if res:
    for i in range(2, int(n**0.5)+1):
        if res%i==0:
            ans=i; break
print(ans)