'''
3671번
산업 스파이의 편지
'''

import sys
input=sys.stdin.readline

prime=[i%2 for i in range(10000000)]
prime[1]=0; prime[2]=1
for i in range(3, 10000000, 2):
    if prime[i]==1:
        for j in range(i+i, 10000000, i):
            prime[j]=0

ans={}
def solve(num, s):
    global ans
    if num!="" and prime[int(num)]==1: 
        ans[int(num)]=True 
    if not s: return
    for i in range(len(s)):
        p=s.pop(i)
        solve(num+p, s)
        s.insert(i, p)

t=int(input())
for _ in range(t):
    ans={}
    s=list(input().rstrip())
    solve("", s)
    print(len(ans))