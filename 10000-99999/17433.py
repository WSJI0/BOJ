'''
17433번
신비로운 수
'''

import sys
input=sys.stdin.readline

def GCD(a, b):
    return b if a%b==0 else GCD(b, a%b)

t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int, input().split()))
    b=[]; cnt=0
    for i in range(n-1):
        if a[i+1]-a[i]==0: 
            cnt+=1
            continue
            
        b.append(abs(a[i+1]-a[i]))
    if cnt==n-1: print("INFINITY"); continue
    b.sort()
    ans=b[0]
    for i in b:
        ans=GCD(ans, i)

    print(ans)