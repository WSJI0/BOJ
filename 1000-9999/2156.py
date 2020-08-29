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
    dp=[a[0], a[0]+a[1], max(a[0]+a[2], a[1]+a[2])]
    for i in range(3, n):
        dp.append(max(dp[i-1]+dp[i-3]+a[i], dp[i-2]+a[i]))
    print(dp)