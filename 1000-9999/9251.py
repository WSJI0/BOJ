'''
9251번
LCS

미완성
'''

import sys
input=sys.stdin.readline

a=input().rstrip()
b=input().rstrip()
ans=0
dp=[[0 for _ in range(len(b))]]
for i in range(1, len(a)):
    d=list(dp[-1])
    for j in range(1, len(b)):
        if a[i-1]==b[i-1]:
            d[j]=dp[-1][j-1]+1
        else:
            

print(ans)