'''
16207번
직사각형
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
a.sort(reverse=True)
b=[]
i=0
while i<n-1:
    if a[i]==a[i+1]: 
        b.append(a[i])
        i+=1
    elif a[i]-1==a[i+1]: 
        b.append(a[i]-1)
        i+=1
    i+=1

ans=0
for i in range(0, len(b)-len(b)%2, 2):
    ans+=b[i]*b[i+1]
print(ans)