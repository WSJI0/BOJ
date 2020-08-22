'''
17298번
오큰수
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
ans=[0]*n
stack=[]

for i in range(n-1, -1, -1):
    while stack and stack[-1]<=a[i]:
        stack.pop()
    if stack:
        ans[i]=stack[-1]
    else:
        ans[i]=-1
    stack.append(a[i])

print(*ans)