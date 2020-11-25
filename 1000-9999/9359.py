'''
9359번
서로소
'''

import sys
input=sys.stdin.readline

t=int(input())
for c in range(1, t+1):
    a, b, n=map(int, input().split())

    div=[n]
    for i in range(2, int(n**0.5)+1):
        if n%i==0:
            div.append(i)
            if n//i!=i: div.append(n//i)

    ans=0
    for i in range(len(div)):
        ans+=(b//div[i])-(a//div[i])-(div[i]//b)+(div[i]//a)
    ans=(b-a)-ans+1

    print("Case #"+str(c)+": "+str(ans))