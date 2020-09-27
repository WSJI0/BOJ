'''
1695번
팰린드롬 만들기

미완성
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))

ans=999999999
for i in range(n):
    L={}; R={}; Ll=[]; Rl=[]; res=0
    for l in range(i+1):
        if a[l] not in L: L[a[l]]=0
        L[a[l]]+=1
        Ll.append(a[l])
    for r in range(i, n):
        if a[r] not in R: R[a[r]]=0
        R[a[r]]+=1
        Rl.append(a[r])
    for l in Ll:
        if l not in R or (l in R and R[l]==0): res+=1
        else: R[l]-=1
    for r in Rl:
        if r not in L or (r in L and L[r]==0): res+=1
        else: L[r]-=1

    ans=min(ans, res)
print(ans)