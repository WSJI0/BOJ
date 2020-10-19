'''
2879번
코딩은 예쁘게
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
b=list(map(int, input().split()))

c=[]; ans=0
for i in range(n):
    c.append(b[i]-a[i])

ans=0
cur=c[0]
for i in range(1, n):
    if c[i]<0:
        if cur>0:
            ans+=cur
            cur=c[i]
        elif cur>c[i]:
            cur=c[i]
        else:
            ans+=abs(cur)-abs(c[i])
            cur=c[i]
    else:
        if cur<0:
            ans+=abs(cur)
            cur=c[i]
        elif cur<c[i]:
            cur=c[i]
        else:
            ans+=abs(cur)-abs(c[i])
            cur=c[i]
ans+=abs(cur)
print(ans)