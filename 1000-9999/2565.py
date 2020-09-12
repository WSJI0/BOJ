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

dp=[[i] for i in range(n)]

for i in range(n):
    for j in range(i):
        if a[dp[j][-1]][1]<a[i][1]:
            dp[j].append(i)

print(n-len(max(dp, key=len)))