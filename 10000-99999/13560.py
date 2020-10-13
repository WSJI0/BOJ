'''
13560번
축구 게임
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
a.sort()
ans=1

pSum=0
for i in range(n):
    