'''
1398번
동전 문제
'''

import sys
input=sys.stdin.readline

coin=[0]
for i in range(1, 25):
    res1=i//10+(i%10)
    res2=i//25+(i%25)
    coin.append(min(res1, res2))
for i in range(25, 100):
    res1=coin[i-10]+1
    res2=coin[i-25]+1
    coin.append(min(res1, res2))

t=int(input())
for _ in range(t):
    n=int(input())
    ans=0
    while n:
        ans+=coin[n%100]
        n//=100
    print(ans)