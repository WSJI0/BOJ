'''
16496번
큰 수 만들기
'''

import sys
input=sys.stdin.readline

def sort2(a):
    for i in range(len(a)-1):
        idx=i
        for j in range(i+1, len(a)):
            if int(a[j]+a[idx])>int(a[idx]+a[j]):
                idx=j
        a[idx], a[i]=a[i], a[idx]

n=int(input())
a=list(input().rstrip().split())
sort2(a); ans=''.join(a)
if a.count('0')==len(a): ans='0'
print(ans)