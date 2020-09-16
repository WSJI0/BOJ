'''
14002번
가장 긴 증가하는 부분 수열 4
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))

dp=[[0]]
for i in range(1, n):
    m=-1; midx=-1
    for j in range(i):
        if a[j]<a[i]:
            if len(dp[j])>m:
                m=len(dp[j])
                midx=j
    if midx!=-1: dp.append(dp[midx]+[i])
    else: dp.append([i])

print(len(max(dp, key=len)))
for i in max(dp, key=len):
    print(a[i], end=' ')
print()