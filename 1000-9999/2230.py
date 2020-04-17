'''
2230번
수 고르기
'''

import sys

word=[]
n, m=list(map(int,sys.stdin.readline().split()))
for _ in range(n):
    a=int(sys.stdin.readline())
    word.append(a)

word.sort()
small=999999999999999999999
i=0
s=1
while i+s<n:
    mi=word[i+s]-word[i]
    if mi>m:
        small=min(small, mi)
        s=1
    elif mi==m:
        small=m
        break
    else:
        s+=1
        continue
    i+=1
print(small)