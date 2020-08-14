'''
2014번
소수의 곱

미완성
'''

import sys
input=sys.stdin.readline

k, n=map(int, input().split())
h=list(map(int, input().split()))

added={}
ans=0
for i in h:
    for j in h:
        if i*j not in added:
            added[i*j]=True
            h.append(i*j)
            if len(h)==n:
                print(h)
                h.sort()
                ans=h
                break
    if ans: break
print(ans)