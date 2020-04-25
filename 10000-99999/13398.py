'''
13398번
연속합 2
'''

import sys

n=int(sys.stdin.readline())
s=list(map(int, sys.stdin.readline().split()))

if n==1:
    print(s[0])
else:
    d=[[s[0],s[0]]]
    ans=s[0]

    for i in range(1,n):
        d.append([s[i],s[i]])

        if d[i-1][0]+s[i]>=s[i]:
            d[i][0]=d[i-1][0]+s[i]
        else:
            d[i][0]=s[i]
        
        if d[i-1][0]>=d[i-1][1]+s[i]:
            d[i][1]=d[i-1][0]
        else:
            d[i][1]=d[i-1][1]+s[i]
        if d[i][0]>=ans or d[i][1]>=ans:
            ans=max(d[i][0],d[i][1])

    print(ans)