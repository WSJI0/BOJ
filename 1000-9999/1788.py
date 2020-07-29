'''
1788번
피보나치 수의 확장
'''

import sys
input=sys.stdin.readline

dp=[0, 1]
for i in range(2, 1000001):
    dp.append((dp[i-2]+dp[i-1])%1000000000)

n=int(input())
if n<0 and n%2==0: print(-1)
elif n==0: print(0)
else: print(1)
print(dp[abs(n)])