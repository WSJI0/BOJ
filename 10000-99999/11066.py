'''
11066번
파일 합치기
'''

import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    k=int(input())
    dp=[[0 for _ in range(k)] for _ in range(k)]
    dp[0]=list(map(int, input().split()))
    for i in range(k):
        for j in range(k):
            pass
    print(dp)