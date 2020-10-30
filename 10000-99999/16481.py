'''
16481번
원 전문가 진우
'''

import sys
input=sys.stdin.readline

r=list(map(int, input().split()))
print((r[0]*r[1]*r[2])/(r[0]*r[1]+r[1]*r[2]+r[0]*r[2]))