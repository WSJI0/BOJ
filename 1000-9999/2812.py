'''
2812번
크게 만들기
'''

import sys
input=sys.stdin.readline

n, k=map(int, input().split())
num=list(map(int, input().rstrip()))

s=[]
for i in range(n):
    while(k and len(s)!=0 and s[-1]<num[i]):
        s.pop()
        k-=1
    s.append(num[i])
for i in range(len(s)-k):
    print(s[i], end='')