'''
18248번
제야의 종
'''

import sys
input=sys.stdin.readline

n, m=map(int, input().split())
l=[]
for _ in range(n):
    l.append(list(map(int, input().split())))
l.sort()


result="YES"
for y in range(1, n):
    for x in range(m):
        if l[y-1][x]>l[y][x]:
            result="NO"
            break
    if result=="NO": break
print(result)
