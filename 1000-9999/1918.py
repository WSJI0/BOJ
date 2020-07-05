'''
1918번
후위 표기식
'''

import sys
input=sys.stdin.readline

a=list(input().rstrip())

def com(n):
    dic={
        '+':1,
        '-':1,
        '*':0,
        '/':0
    }
    return dic[n]

stack=[]
for i in a:
    if i.isalpha():
        print(i, end='')
    else:
        if len(stack)==0:
            stack.append(i)
        else:
            if com(i)<=com(stack[-1]):
                print(stack.pop(), end='')
                stack.append(i)
            else:
                stack.append(i)
for i in stack:
    print(i, end='')