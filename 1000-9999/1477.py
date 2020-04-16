'''
1477번
휴게소 세우기
'''

import sys

n, m, l=map(int,sys.stdin.readline().split())
road=list(map(int,sys.stdin.readline().split()))
road.sort()

print(road)