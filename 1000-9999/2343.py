'''
2343번
기타 레슨
'''

import sys
input=sys.stdin.readline

n, m=map(int, input().split())
a=list(map(int, input().split()))

l=max(a)
r=sum(a)

def check(mid):
    global n, m, a
    byte=mid
    cd=1

    if mid<max(a):
        return False

    for i in a:
        if byte>=i:
            byte-=i
        else:
            cd+=1
            byte=mid-i
    if cd>m:
        return False
    else:
        return True
    

while(l<=r):
    mid=(l+r)//2
    
    if check(mid):
        ans=mid
        r=mid-1
    else:
        l=mid+1

print(ans)