'''
1037번
약수
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
a.sort()
print(a[0]*a[-1])