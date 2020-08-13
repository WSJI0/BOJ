'''
4913번
페르마의 크리스마스 정리
'''

import sys
from collections import deque
input=sys.stdin.readline

def isPrime(n):
    for i in range(2, int(n**0.5)+1):
        if n%i==0:
            return False
    return True

prime=deque([0,0,1])
for i in range(3, 1000000, 2):
    if isPrime(i): prime.append(1)
    else: prime.append(0)
    prime.append(0)

while True:
    l, u=map(int, input().split())
    if l==u==-1: break
    x=0; y=0
    for i in range(l, u+1):
        if prime[i]==1: 
            x+=1
            if (i-1)%4==0: y+=1
    print(l, u, x, y)