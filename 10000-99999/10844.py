'''
10844번
쉬운 계단 수
'''

import sys
input=sys.stdin.readline

n=int(input())

dp=[0,1,1,1,1,1,1,1,1,1]

for i in range(1, n):
    a=[0]*10
    for j in range(10):
        if j==0: a[1]+=dp[j]
        elif j==9: a[8]+=dp[j]
        else: 
            a[j-1]+=dp[j]
            a[j+1]+=dp[j]
    dp=a

print(sum(dp)%1000000000)