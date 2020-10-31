'''
16637번
괄호 추가하기

미완성
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
p=deque(input().rstrip())

def cal(a, b, o):
    if o=='+': return a+b
    if o=='-': return a-b
    if o=='*': return a*b

ans=0
def solve(p):
    global ans
    if len(p)==1: 
        ans=max(ans, p[0])
        return

    c=cal(cal(p[0], p[1], p[2]))
    po=deque()
    for _ in range(3): po.append(cal.popleft())
    p.appendleft(c)
    solve(p)
    p.popleft()
    for i in range(3): p.appendleft(po.popleft())

solve(p)
print(ans)