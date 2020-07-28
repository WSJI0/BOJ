'''
1912번
연속합
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))

dp=[a[0]]
for i in range(1, n):
    if dp[i-1]<0:
        dp.append(a[i])
        continue
    dp.append(dp[i-1]+a[i])

print(max(dp))