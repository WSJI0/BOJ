'''
18258번
큐 2
'''

import sys
from collections import deque
input=sys.stdin.readline

queue=deque()
n=int(input())
for _ in range(n):
    com=input().rstrip()
    if com.count("push"):
        queue.append(int(com.split(' ')[1]))
        continue
    if com=="front":
        if len(queue)==0: print(-1)
        else: print(queue[0])
    elif com=="back":
        if len(queue)==0: print(-1)
        else: print(queue[-1])
    elif com=="empty":
        print(1 if len(queue)==0 else 0)
    elif com=="size":
        print(len(queue))
    elif com=="pop":
        if len(queue)==0: print(-1)
        else: print(queue.popleft())