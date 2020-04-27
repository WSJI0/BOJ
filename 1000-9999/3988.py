'''
3988번
수 고르기
'''

import sys

n, k=map(int, sys.stdin.readline().split())

num=list(map(int, sys.stdin.readline().split()))
num.sort()

d=[]
ans=9999999999999
i=0
J=1
for i in range(n-k):
    if len(d)!=0:
        if d[0]<=i:
            d.pop(0)

    for j in range(1, i+n-k):
        if len(d)!=0:
            if num[j]-num[j-1]<=num[d[0]]-num[d[0]-1]:
                d.pop()
        d.append(j)

    ans=min(ans,num[d[0]]-num[d[0]-1]+num[i+n-k-1]-num[i])

print(ans)