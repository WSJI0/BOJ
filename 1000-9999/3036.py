'''
3036번
링
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))

def GCD(a, b):
    return b if a%b==0 else GCD(b, a%b)

for i in range(1, n):
    g=GCD(a[0], a[i])
    print(str(a[0]//g)+"/"+str(a[i]//g))