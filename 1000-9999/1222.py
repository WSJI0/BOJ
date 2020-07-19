'''
1222번
홍준 프로그래밍 대회
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))

num=[0]*2000002
for i in a:
    num[i]+=1

ans=0
for i in range(1, 2000001):
    cnt=0
    for j in range(i, 2000001, i):
        cnt+=num[j]
    if cnt>1:
        ans=max(ans, cnt*i)

print(ans)