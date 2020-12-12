'''
3165번
5

미완성
'''

import sys
sys.setrecursionlimit(10**6)
input=sys.stdin.readline

n, k=map(int, input().split())
N=str(n)

def solve(num, d, cnt):
    if d==len(N):
        if cnt==k and num>n:
            print(num)
            sys.exit()
        return

    if num>
    for i in range(10):
        if d==0 and i==0: continue
        if i!=5: 
            solve(num*10+i, d+1, cnt)
        else: 
            solve(num*10+i, d+1, cnt+1)


if n<int('5'*k): print('5'*k)
else: solve(0, 0, 0)