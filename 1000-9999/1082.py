'''
1082번
방 번호
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
m=int(input())

res=99; s=0
for i in range(n):
    if res>=a[i]:
        s=i
        res=a[i]

num=deque()
while m>0:
    m-=a[s]
    if m>=0: num.append(s)
    else: m+=a[s]; break

if num[0]==0 and len(num)!=1:
    changed=False
    while not changed:
        m+=a[0]
        for i in range(n-1, -1, -1):
            if a[i]<=m and i!=0:
                num[0]=i
                m-=a[i]
                changed=True
                break
            if i==0: num.popleft()
        if changed or len(num)==0: break
    if len(num)==0: num=[0]

while m>0 and num!=[0]:
    for i in range(len(num)):
        m+=a[num[i]]
        for j in range(n-1, num[i]-1, -1):
            if a[j]<=m:
                num[i]=j
                m-=a[j]
                break
    if res>m: break

print(''.join(map(str, num)))