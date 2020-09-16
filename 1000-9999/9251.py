'''
9251번
LCS

미완성
'''

import sys
input=sys.stdin.readline

a='0'+input().rstrip()
b='0'+input().rstrip()
if len(a)<len(b): a, b=b, a

dp=[0]*len(a)
for i in range(len(b)):
    for j in range(1, len(a)):
        if dp[j]<dp[j-1]: dp[j]=dp[j-1]
        if b[i]==a[j]: dp[j]+=1
    print(dp)
    
#print(dp)