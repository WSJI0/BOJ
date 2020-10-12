'''
11402번
이항 계수 4
'''

import sys
input=sys.stdin.readline

n, k, m=map(int, input().split())

b=[]
for i in range(m):
    b.append([0]*2001); b[i][0]=1
    for j in range(1, i+1):
        b[i][j]=(b[i-1][j-1]+b[i-1][j])%m
    
res=1
while n or k:
    res*=b[n%m][k%m]
    n//=m; k//=m; res%=m

print(res)