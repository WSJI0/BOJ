'''
1493번
박스채우기

미완성
'''

import sys
input=sys.stdin.readline

l, w, h=map(int, input().split())
n=int(input())

cube=[]
for _ in range(n):
    size, num=map(int, input().split())
    cube.append([1<<size, num])

print(cube)