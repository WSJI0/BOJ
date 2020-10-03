'''
19623번
회의실 배정 4
'''

import sys
input=sys.stdin.readline

n=int(input())
conf=[]
for _ in range(n):
    conf.append(list(map(int, input().split())))

conf.sort(key=lambda k:k[1])

dp=[conf[0]]
for i in range(1, n):
    conf.