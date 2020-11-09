'''
2457번
공주님의 정원

미완성
'''

import sys
input=sys.stdin.readline

n=int(input())
md=[]
for _ in range(n):
    m1, d1, m2, d2=map(int, input().split())
    md.append([m2, d2, m1, d1])

md.sort()
print(md)