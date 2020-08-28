'''
11399번
ATM
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))

a.sort(reverse=True)
ans=0
for i in range(n):
    ans+=(i+1)*a[i]

print(ans)