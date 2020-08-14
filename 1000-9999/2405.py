'''
2405번
세 수, 두 M
'''

import sys
input=sys.stdin.readline

n=int(input())
a=[]
for _ in range(n):
    a.append(int(input()))
a.sort()

ans=0
for i in range(n-1):
    ans=max(ans, abs(a[i]-2*a[i+1]+a[-1]), abs(-a[0]-a[i+1]+a[i]*2))
if n==3:
    print(abs(a[0]-2*a[1]+a[2]))
else: print(ans)