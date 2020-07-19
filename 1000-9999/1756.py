'''
1756번
피자 굽기

미완성
'''

import sys
from collections import deque
input=sys.stdin.readline

d, n=map(int, input().split())
oven=deque(map(int, input().split()))
p=deque(map(int, input().split()))

print(p)