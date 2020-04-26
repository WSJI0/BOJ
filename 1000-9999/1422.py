'''
1422번
숫자의 신
'''

import sys

k,n=map(int, sys.stdin.readline().split())

a=[]
maxLen=0
for _ in range(k):
    w=str(sys.stdin.readline().rstrip())
    a.append(w)
    maxLen=max(maxLen, len(w))
a2=list(a)

for i in range(k):
    if len(a[i])<maxLen:
        for _ in range(maxLen-len(a[i])):
            a[i]+='a'

a.sort(reverse=True)

for j in range(k):
    print(a[j].split('a')[0], end=' ')
for _ in range(n-k):
    print(a2[0], end=' ')