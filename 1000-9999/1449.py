'''
1449번
수리공 항승
'''

import sys
input=sys.stdin.readline

n, l=map(int, input().split())
a=list(map(int, input().split()))
a.sort()

L=0
cnt=0
for R in a:
    if L<R:
        L=R+l-1
        cnt+=1
print(cnt)