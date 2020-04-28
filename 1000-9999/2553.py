'''
2553번
마지막 팩토리얼 수
'''

import sys
n=int(sys.stdin.readline())

fac=1
for i in range(1, n+1):
    fac*=i
    fac%=100000000
    while fac%10==0:
        fac//=10

print(fac%10)