'''
16637번
괄호 추가하기
'''

import sys
input=sys.stdin.readline

n=int(input())
pre=input().rstrip()

for i in range(n):
    if i%2==0:
