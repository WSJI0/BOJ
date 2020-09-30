'''
1398번
동전 문제
'''

import sys
input=sys.stdin.readline

coin=[]
for i in range(16):
    coin.extend([pow(10, i), 25*pow(100, i)])
coin.sort(reverse=True)
print(coin)
t=int(input())
for _ in range(t):
    n=int(input())
    ans=0
    for i in range(len(coin)):
        ans+=n//coin[i]
        n=n%coin[i]
    print(ans)