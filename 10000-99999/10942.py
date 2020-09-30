'''
10942번
팰린드롬?

미완성
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))

palindrome={}
dp=list(a)
for i in range(n):
    b=[]
    for j in dp:
        if j

m=int(input())
for _ in range(m):
    s, e=map(int, input().split())
    if (s, e) in palindrome:
        print(1)
    else: print(0)