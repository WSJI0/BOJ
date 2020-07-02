'''
6549번
히스토그램에서 가장 큰 직사각형
'''

import sys
input=sys.stdin.readline

while True:
    his=list(map(int, input().split()))
    n=his[0]
    if n==0: break
    his=his[1:]

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