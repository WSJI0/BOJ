'''
2981번
검문
'''

import sys
input=sys.stdin.readline

def GCD(a, b):
    return b if a%b==0 else GCD(b, a%b)

def divisor(n):
    d=[]
    for i in range(1, int(n**0.5)+1):
        if n%i==0:
            d.append(i)
            if n//i!=i: d.append(n//i)
    return d

n=int(input())
a=[]
for _ in range(n):
    a.append(int(input()))
a.sort()
m=a[1]-a[0]
for i in range(n-1):
    m=GCD(a[i+1]-a[i], m)

print(*list(sorted(divisor(m)))[1:])