'''
1717번
집합의 표현
'''

import sys
from collections import deque
input=sys.stdin.readline

n, m=map(int, input().split())
SET=deque()
for i in range(n+1):
    SET.append({i:True})

for i in range(m):
    op, a, b=map(int, input().split())
    if op==0:
        SET[a].update(SET[b])
        SET[b]=SET[a]
    elif op==1:
        if b in SET[a]:
            print("YES")
        else:
            print("NO")