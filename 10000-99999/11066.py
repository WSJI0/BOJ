'''
11066번
파일 합치기
'''

import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    k=int(input())
    a=list(map(int, input().split()))
    dp=[]
    for _ in range(500): dp.append([0 for _ in range(500)])
    for i in range(k):
        for j in range(k):
            

    print(dp)
    print(dp[-1])