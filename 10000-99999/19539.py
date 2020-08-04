'''
19539번
사과나무
'''

import sys
input=sys.stdin.readline

n=int(input())
h=list(map(int, input().split()))

cnt=0
if sum(h)%3==0:
    for i in h: cnt+=i//2
    if cnt>=sum(h)//3:
        print("YES")
    else: 
        print("NO")
else:
    print("NO")