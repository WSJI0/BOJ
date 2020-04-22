'''
3988번
수 고르기
'''

import sys

n, k=map(int, sys.stdin.readline().split())

num=list(map(int, sys.stdin.readline().split()))
num.sort()

for _ in range(k):
    left=num[1]-num[0]
    right=num[-1]-num[-2]
    if left>right:
        num.pop()
    elif left<right:
        num.pop(0)
    else:
        left=num[len(num)//2]-num[0]
        right=num[-1]-num[len(num)//2]
        if left>right:
            num.pop(0)
        else:
            num.pop()

print(num)