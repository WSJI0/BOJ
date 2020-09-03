'''
17828번
문자열 화폐
'''

import sys
input=sys.stdin.readline

n, x=map(int, input().split())

ans=['A']*n
if x<n: ans='!'
x-=n
i=0
while x>0:
    if x>=25:
        if i==n-1 and x>25:
            ans='!'
            break
        ans[i]='Z'
        i+=1
        x-=25
    else:
        ans[i]=chr(x+65)
        x=0

print(''.join(list(reversed(ans))))