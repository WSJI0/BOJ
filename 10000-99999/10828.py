'''
10828번
스택
'''

import sys

n=int(sys.stdin.readline())

s=[]

def push(e):
    s.append(e)

def pop():
    try:
        print(s[-1])
        s.pop()
    except:
        print(-1)

def size():
    print(len(s))

def empty():
    print(1 if len(s)==0 else 0)

def top():
    try:
        print(s[-1])
    except:
        print(-1)

for _ in range(n):
    command=list(sys.stdin.readline().split())
    if command[0]=="push":
        push(int(command[1]))
    elif command[0]=="pop":
        pop()
    elif command[0]=="size":
        size()
    elif command[0]=="empty":
        empty()
    elif command[0]=="top":
        top()