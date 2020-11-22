'''
14677번
병약한 윤호
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
drug=list(input().rstrip())

ans=0
q=deque()
if drug[0]=='B': q.append([1, 3*n-1, 1])
if drug[3*n-1]=='B': q.append([0, 3*n-2, 1])

ans=0
while q:
    l, r, res=q.popleft()
    ans=max(ans, res)
    if res==n*3: break
    if res%3==0:
        if drug[l]=='B': q.append([l+1, r, res+1])
        if drug[r]=='B': q.append([l, r-1, res+1])
    elif res%3==1:
        if drug[l]=='L': q.append([l+1, r, res+1])
        if drug[r]=='L': q.append([l, r-1, res+1])
    else:
        if drug[l]=='D': q.append([l+1, r, res+1])
        if drug[r]=='D': q.append([l, r-1, res+1])

print(ans)