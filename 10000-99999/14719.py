'''
14719번
빗물
'''

import sys
input=sys.stdin.readline

h, w=map(int, input().split())
a=list(map(int, input().split()))

ans=0
for i in range(1, w-1):
    ans+=max(0, min(max(a[:i]), max(a[i+1:]))-a[i])
print(ans)