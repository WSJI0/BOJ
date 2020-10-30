'''
4994번
배수 찾기
'''

import sys
from collections import deque
input=sys.stdin.readline

while True:
    n=int(input())
    if n==0: break

    q=deque([1])
    visited={}
    while q:
        node=q.popleft()
        if (node*10)%n!=0 and (node*10+1)%n!=0:
            if (node*10)%n not in visited: 
                q.append(node*10)
                visited[(node*10)%n]=True
            if (node*10+1)%n not in visited: 
                q.append(node*10+1)
                visited[node*10+1]=True
        else:
            if (node*10)%n==0:
                print(node*10)
            elif (node*10+1)%n==0:
                print(node*10+1)
            break