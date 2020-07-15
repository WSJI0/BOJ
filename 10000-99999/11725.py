'''
11725번
트리의 부모 찾기
'''

import sys
input=sys.stdin.readline

graph={}

n=int(input())
ans=[0]*(n+1)

for _ in range(n-1):
    a, b=map(int, input().split())
    