'''
1644번
소수의 연속합
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
prime=deque()

p=[i%2 for i in range(n+2)]
p[1]=0; p[2]=1
for i in range(3, n+1, 2):
    if p[i]==1:
        for j in range(i+i, n+1, i):
            p[j]=0

for i in range(2, n+1):
    if p[i]: prime.append(i)

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
    if n==2: return True
    if n==1 or n%2==0: return False
    for i in range(3, int(n**0.5)+1, 2):
        if n%i==0: return False
    return True

if isPrime(n): ans+=1
print(ans)