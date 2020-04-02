'''
10989번
수 정렬하기 3
'''

import sys

n=int(input())
co=[0]*10001
for i in sys.stdin:
    co[int(i)]+=1

for j in range(10001):
    if co[j]!=0:
        for _ in range(co[j]):
            print(j)