'''
1644번
소수의 연속합

시간초과
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())

prime=deque([2])
for num in range(3, n+1):
    no=False
    for i in prime:
        if i>int(num**0.5)+1: break
        if num%i==0: 
            no=True
            break
    if not no: prime.append(num)

l=0; r=0; s=2; ans=0

while r<len(prime)-1 and l<=r:
    if s<n:
        r+=1
        s+=prime[r]
    else:
        s-=prime[l]
        l+=1
    if s==n:
        ans+=1

def isPrime(n):
    if n%2==0: return False
    for i in range(3, int(n**0.5)+1, 2):
        if n%i==0: return False
    return True

if isPrime(n): ans+=1
print(ans)