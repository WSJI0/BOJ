'''
2042번
구간 합 구하기

미완성
'''

import sys
input=sys.stdin.readline

n, m, k=map(int, input().split())
a=[]
for _ in range(n):
    a.append(int(input()))

for _ in range(m+k):
    