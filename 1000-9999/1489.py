'''
1489번
대결

미완성
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
b=list(map(int, input().split()))
a.sort()
b.sort()
for i in range(n):
