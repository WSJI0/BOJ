'''
17497번
계산기
'''

import sys
input=sys.stdin.readline

n=int(input())
ans=[]
if n%2==1:
    n*=2
    ans.append('[/]')
    
while n!=0:
    if n%2==0:
        if n==2:
            ans.append('[+]')
            n-=2
            continue
        n//=2
        ans.append('[*]')
    else:
        n*=2
        if ans: ans.pop()
        n+=2
        ans.append('[-]')

print(len(ans))
print(*list(reversed(ans)))