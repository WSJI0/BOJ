'''
1918번
후위 표기식
'''

import sys
input=sys.stdin.readline

a=list(input().rstrip())
a.insert(0, '(')
a.append(')')

def com(n):
    dic={
        '*':1,
        '/':1,
        '+':0,
        '-':0,
        '(':-1
    }
    return dic[n]

stack=[]
for i in a:
    if i.isalpha():
        print(i, end='')
    elif i=='(':
        stack.append(i)
    elif i==')':
        while stack[-1]!='(':
            print(stack.pop(), end='')
        stack.pop()
    else:
        while len(stack)!=0 and stack[-1]!='(' and com(i)<=com(stack[-1]):
            print(stack.pop(), end='')
        stack.append(i)
        
for i in stack:
    print(i, end='')