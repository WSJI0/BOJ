'''
10866번
덱
'''

import sys

n=int(sys.stdin.readline())

s=[]

def push_front(e):
    s.append(e)

def push_back(e):
    s.insert(0, e)

def pop_front():
    try:
        print(s[-1])
        s.pop()
    except:
        print(-1)

def pop_back():
    try:
        print(s[0])
        s.pop(0)
    except:
        print(-1)

def size():
    print(len(s))

def empty():
    print(1 if len(s)==0 else 0)

def front():
    try:
        print(s[-1])
    except:
        print(-1)

def back():
    try:
        print(s[0])
    except:
        print(-1)

for _ in range(n):
    command=list(sys.stdin.readline().split())
    if command[0]=="push_front":
        push_front(int(command[1]))
    elif command[0]=="push_back":
        push_back(int(command[1]))
    elif command[0]=="pop_front":
        pop_front()
    elif command[0]=="pop_back":
        pop_back()
    elif command[0]=="size":
        size()
    elif command[0]=="empty":
        empty()
    elif command[0]=="front":
        front()
    elif command[0]=="back":
        back()