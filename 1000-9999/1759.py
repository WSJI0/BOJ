'''
1759번
암호 만들기

미완성
'''

import sys
input=sys.stdin.readline

l, c=map(int, input().split())
a=list(input().rstrip().split())

def backT(cur, prev, next, password):
    