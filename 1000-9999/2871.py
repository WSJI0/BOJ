'''
2871번
아름다운 단어

시간초과
'''

import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
w=list(input().rstrip())

word={}
for i in range(97, 123): word[chr(i)]=deque()
for i in range(n): word[w[i]].append(i)

a=deque(); b=deque(); l=n-1
for i in range(n-1, -1, -1):
    if i%2==(n-1)%2:
        for j in range(l, -1, -1):
            if word[w[j]] and word[w[j]][-1]==j:
                b.append(w[j])
                word[w[j]].pop()
                break
    else:
        for j in range(97, 123):
            if word[chr(j)]:
                a.append(chr(j))
                word[chr(j)].pop()
                break

A=''.join(a)
B=''.join(b)
if A==B or A>B: print('NE')
else: print('DA')
print(A)