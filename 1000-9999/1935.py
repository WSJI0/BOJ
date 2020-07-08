'''
1935번
후위 표기식2
'''

import sys
input=sys.stdin.readline

n=int(input())
ex=list(input().rstrip())

num=[]
for _ in range(n):
    num.append(input().rstrip())

stack=[]
for i in ex:
    if i.isalpha():
        stack.append(num[ord(i)-65])
    else:
        B=stack.pop()
        A=stack.pop()
        stack.append(str(eval(A+i+B)))

print("%.2f" %float(stack[0]))