'''
2579번
계단 오르기
'''

import sys
input=sys.stdin.readline

n=int(input())
s=[]
for _ in range(n):
    s.append(int(input()))

if len(s)<3:
    print(sum(s))
else:
    dp=[s[0], s[0]+s[1], max(s[0]+s[2], s[1]+s[2])]
    for i in range(3, n):
        dp.append(max(dp[i-3]+s[i-1]+s[i], dp[i-2]+s[i]))
    
    print(dp[-1])