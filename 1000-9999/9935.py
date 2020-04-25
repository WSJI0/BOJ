'''
9935번
문자열 폭발
'''

import sys

word=list(sys.stdin.readline())[:-1]
bomb=list(sys.stdin.readline())[:-1]

stack=[]
for i in range(len(word)):
    stack.append(word[i])
    if len(stack)>=len(bomb):
        if stack[len(stack)-len(bomb):]==bomb:
            for _ in range(len(bomb)):
                stack.pop()

if len(stack)==0:
    print("FRULA")
else:
    print(''.join(stack))