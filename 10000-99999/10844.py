'''
10844번
쉬운 계단 수
'''

import sys
input=sys.stdin.readline

n=int(input())

dp=[[0,0,0,0,0,0,0,0,0,0]*100]
cnt=0

for i in range(1, 10):
    