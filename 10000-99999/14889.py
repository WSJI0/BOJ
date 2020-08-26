'''
14889번
스타트와 링크
'''

import sys
input=sys.stdin.readline

n=int(input())
score=[]
for _ in range(n):
    score.append(list(map(int, input().split())))

team=[0 for _ in range(n)]
ans=999999999999999
def solve(a, b):
    global ans, n
    if a==n//2:
        print(a)
        return

    for i in range(n):
        