'''
11066번
파일 합치기
(미완성)
'''

import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    k=int(input())
    a=list(map(int, input().split()))
    dp=[a[0]]
    for i in range(1, k):
        dp.append(dp[-1])
    print(dp[-1])