'''
1707번
이분 그래프

미완성
'''

import sys
input=sys.stdin.readline

k=int(input())
for _ in range(k):
    v, e=map(int, input().split())
    nodes=[]
    for _ in range(e):
        nodes.append(list(map(int, input().split())))
    
