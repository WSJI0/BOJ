'''
2104번
부분배열 고르기 (미완성)
'''

import sys
input=sys.stdin.readline

n=int(input())

his=list(map(int, input().split()))

stack=[]
ans=0
for i in range(n):
    left=i
    while(len(stack)!=0 and his[stack[-1]]>his[i]):
        height=his[stack.pop()]
        width=i
        if len(stack)!=0:
            width=i-stack[-1]-1
        if ans<width*height:
            ans=width*height
    stack.append(i)

while(len(stack)!=0):
    height=his[stack.pop()]
    width=n
    if len(stack)!=0:
        width=n-stack[-1]-1
    if ans<width*height:
        ans=width*height

print(ans)