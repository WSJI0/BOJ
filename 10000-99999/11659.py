'''
11659번
구간 합 구하기 4
'''

import sys
input=sys.stdin.readline

n, m=map(int, input().split())
a=list(map(int, input().split()))

pSum=[0]
for i in range(1, n+1):
    pSum.append(pSum[i-1]+a[i-1])

for _ in range(m):
    i, j=map(int, input().split())
    i, j=min(i, j), max(i, j)
    print(pSum[j]-pSum[i-1])