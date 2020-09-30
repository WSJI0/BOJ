'''
5557번
1학년

미완성
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
a.reverse()

print(a[1:])

dp=[a[0]]
for i in range(1, n-1):
    b=[]; bd={}
    for j in dp:
        if (j-a[i]) not in bd:
            bd[j-a[i]]=True
            b.append(j-a[i])
        if (j+a[i]) not in bd:
            bd[j+a[i]]=True
            b.append(j+a[i])
    dp=b
    print(dp)

ans=0
for i in dp:
    if abs(i)==abs(a[-1]): ans+=1

print(ans)