'''
17215번
볼링 점수 계산
'''

import sys
input=sys.stdin.readline

s=input().rstrip()

frame=1
turn=10
score=0
for i in range(len(s)):
    if s[i]=='S':
        if frame==10: turn=12
    

    if frame==turn: break