'''
6143번
문자열 생성 2
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
s=deque()
for i in range(n):
    s.append(input().rstrip())

cnt=0
while s:
    if cnt!=0 and cnt%80==0: print()
    if s[0]>s[-1]:
        print(s.pop(), end='')
        cnt+=1
    elif s[0]<s[-1]:
        print(s.popleft(), end='')
        cnt+=1
    else:
        l=0; r=len(s)-1
        while s[l]==s[r] and l<r:
            l+=1; r-=1
        if s[l]>s[r]:
            for _ in range(l):
                print(s.pop(), end='')
                print(s.popleft(), end='')
                cnt+=2
        else:
            for _ in range(l):
                print(s.pop(), end='')
                print(s.popleft(), end='')
                cnt+=2