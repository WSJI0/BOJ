'''
8111번
0과 1

미완성
'''

import sys
from collections import deque
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n=int(input())
    
    q=deque()
    q.append(1)
    visited={}
    while q:
        node=q.popleft()
        if node not in visited:
            visited[node]=True
            if (node*10)%n!=0 and (node*10+1)%n!=0:
                q.extend([(node*10), (node*10+1)])
            else:
                if (node*10)%n==0:
                    print(node*10)
                elif (node*10+1)%n==0:
                    print(node*10+1)
                break