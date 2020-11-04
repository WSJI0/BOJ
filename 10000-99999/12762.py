'''
12762번
롤러코스터
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))

dp=[1]
dp2=[1]
dp3=[1]
dp4=[1]
for i in range(1, n): #해당 인덱스까지 오르막
    m=0
    for j in range(i):
        if a[j]<a[i]:
            m=max(m, dp[j])
    dp.append(m+1)

for i in range(1, n): #해당 인덱스에서 내리막
    m=0
    for j in range(i):
        if a[j]>a[i]:
            m=max(m, dp2[j])
    dp2.append(m+1)

for i in range(1, n): #해당 인덱스에서 오르막
    m=0
    for j in range(i):
        if a[j]<a[i]:
            m=max(m, dp3[j])
    dp3.append(m+1)

for i in range(1, n): #해당 인덱스까지 내리막
    m=0
    for j in range(i):
        if a[j]>a[i]:
            m=max(m, dp4[j])
    dp4.append(m+1)

ans=max(dp2)
for i in range(n):
    ans=max(dp[i]+dp2[i]-1, ans)
for i in range(n):
    ans=max(dp3[i]+dp4[i]-1, ans)
    
print(ans)