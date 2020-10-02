'''
1892번
가위바위보
'''

import sys
input=sys.stdin.readline

def nCr(n, r):
    fac=[1,1]
    for i in range(2, n+1):
        rac.append(fac[-1]*i)
    return fac[n]//(fac[r]*fac[n-r])

def GCD(a, b):
    return b if a%b==0 else GCD(b, a%b)

n, k=map(int, input().split())
A=pow(2, n-min(n, 2*k-1))
B=pow(3, min(n, 2*k-1))
G=GCD(A, B)
print(A//G, B//G)