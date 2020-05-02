'''
12015번
가장 긴 증가하는 부분 수열 2
'''

import sys

n=int(sys.stdin.readline())
a=list(map(int, sys.stdin.readline().split()))

cur=a[0]
cnt=1
for i in range(1,n):
    if a[i]>cur:
        cur=a[i]
        cnt+=1
print(cnt)