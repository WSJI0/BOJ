'''
1422번
숫자의 신
'''

import sys

k,n=map(int, sys.stdin.readline().split())

a=[]; l=0
for _ in range(k):
    num=int(input())
    a.append(num)
    l=max(l, len(str(num)))

if n!=len(a):
    for _ in range(n-len(a)):
        a.append(max(a))

for i in range(n):
    a[i]=str(a[i])+'a'*(l-len(str(a[i])))

a.sort(reverse=True)

a=''.join(a).replace('a','')
print(a)