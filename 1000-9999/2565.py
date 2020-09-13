'''
2565번
전깃줄
'''

import sys
input=sys.stdin.readline

n=int(input())
a=[]
for _ in range(n):
    a.append(list(map(int, input().split())))
a.sort()

dp=[1 for _ in range(n)]
for i in range(n):
    m=0
    for j in range(i):
        if a[j][1]<a[i][1]:
            m=max(dp[j], m)
    dp[i]+=m
            
print(n-max(dp))