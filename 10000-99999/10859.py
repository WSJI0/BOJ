'''
10859번
뒤집어진 소수
'''

import sys
input=sys.stdin.readline

n=input().rstrip()[::-1]
ori=int(n[::-1])
new=''
ans='yes'
for i in range(len(n)):
    if n[i]=='6': new+='9'
    elif n[i]=='9': new+='6'
    elif n[i]=='3' or n[i]=='4' or n[i]=='7': ans='no'
    else: new+=n[i]

if len(new)!=0:
    new=int(new)
    for i in range(2, int(new**0.5)+1):
        if new%i==0:
            ans='no'
            break
    for i in range(2, int(ori**0.5)+1):
        if ori%i==0:
            ans='no'
            break
if new==1: ans='no'
print(ans)