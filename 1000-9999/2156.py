'''
2156번
포도주 시식
'''

import sys
input=sys.stdin.readline

n=int(input())
a=[0]
for _ in range(n):
    a.append(int(input()))

if len(a)<=3:
    print(sum(a))
else:
    dp=[0, a[1], a[1]+a[2]]
    for i in range(3, n+1):
        dp.append(max(dp[i-3]+a[i-1]+a[i], dp[i-2]+a[i]))
        dp[-1]=max(dp[-1], dp[-2])
    
    print(max(dp))