'''
2156번
포도주 시식
'''

import sys
input=sys.stdin.readline

n=int(input())
a=[]
for _ in range(n):
    a.append(int(input()))

if len(a)<3:
    print(sum(a))
else:
    dp=[0, a[0], a[0]+a[1]]
    for i in range(3, n):
        dp.append(max(dp[i-1], dp[i-2]+a[i], dp[i-3], dp[i-1]+a[i]))
    
    print(max(dp))