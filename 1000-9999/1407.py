'''
1407번
2로 몇 번 나누어질까
'''

import sys
input=sys.stdin.readline

a, b=map(int, input().split())
for i in range(a, b+1):
    if 