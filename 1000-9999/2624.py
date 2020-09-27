'''
2624번
동전 바꿔주기
'''

import sys
input=sys.stdin.readline

t=int(input())
k=int(input())
m={}
for _ in range(k):
    a, b=map(int, input().split())
    m[a]=b

