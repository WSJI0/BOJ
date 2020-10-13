'''
10165번
버스 노선

미완성
'''

import sys
input=sys.stdin.readline

n=int(input())
m=int(input())
bus=[]
for i in range(1, m+1):
    bus.append(list(map(int, input().split()))+[i])

bus.sort(key=lambda k: abs(k[0]-k[1]), reverse=True)
print(bus)