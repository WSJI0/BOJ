'''
11726번
2×n 타일링
'''

import sys
input=sys.stdin.readline

n=int(input())

dp=[1, 1]
for i in range(2, n+1):
    dp.append(dp[i-1]+dp[i-2])
print(dp[n]%10007)