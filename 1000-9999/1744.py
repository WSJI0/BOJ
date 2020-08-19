'''
1744번
수 묶기
'''

import sys
input=sys.stdin.readline

n=int(input())

neg=[]
zero=[]
pos=[]
ans=0
for _ in range(n): 
    i=int(input())
    if i>1: pos.append(i)
    elif i==0: zero.append(i)
    elif i==1: ans+=1
    else: neg.append(i)

pos.sort(reverse=True)
neg.sort()

for i in range(0, len(neg)-1, 2):
    ans+=neg[i]*neg[i+1]
if len(neg)%2==1:
    if len(zero)==0: ans+=neg[-1]

for i in range(0, len(pos)-1, 2):
    ans+=pos[i]*pos[i+1]
if len(pos)%2==1: ans+=pos[-1]

print(ans)