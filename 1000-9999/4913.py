'''
4913번
페르마의 크리스마스 정리
'''

import sys
input=sys.stdin.readline

prime=[i%2 for i in range(1000001)]
prime[1]=0
prime[2]=2
for i in range(3, 1000001, 2):
    if prime[i]==1 and (i-1)%4==0: prime[i]=2
    for j in range(i+i, 1000001, i):
        prime[j]=0

cnt=[0]
cnt2=[0]
for i in range(1, 1000001):
    cnt.append(cnt[-1]+min(1, prime[i]))
    cnt2.append(cnt2[-1]+(1 if prime[i]==2 else 0))

while True:
    l, u=map(int, input().split())
    if l==u==-1: break
    x=cnt[u]-cnt[l-1]
    y=cnt2[u]-cnt2[l-1]

    print(l, u, x, y)