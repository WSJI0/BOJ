'''
19543번
던전 지도
'''

import sys
input=sys.stdin.readline

n, m, k=map(int, input().split())

block=[0]*k
for i in range(k):
    block[i]=input().rstrip()

room=list(input().rstrip())

dungeon=[]
for i in range(n):
    dungeon.append(ord(room[-i-1])-65)

ans=0; l=m-1; r=m-1
while (l>0 and block[dungeon[0]][l-1]=='R'):
    l-=1

for i in range(1, n):
    ans+=r-l+1
    L=l-1; R=r
    while(R>=l):
        if block[dungeon[i]][R]=='U': break
        R-=1
    if R<l: break
    while(L>=0):
        if block[dungeon[i]][L]=='U': break
        L-=1
    l=L+1; r=R
    if i==n-1: ans+=r-l+1

if n==1:
    ans+=r-l+1

print(ans)