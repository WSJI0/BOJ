'''
15732번
도토리 숨기기

시간초과
'''

import sys
import time
input=sys.stdin.readline

n, k, d=map(int, input().split())

rule=[]
for _ in range(k):
    rule.append(list(map(int, input().split())))

print("START")
start=time.time()
box={}
for i in rule:
    for j in range(i[0], i[1]+1, i[2]):
        if j not in box:
            box[j]=0
        box[j]+=1
box=sorted(box.items())

l=0
r=len(box)

while(l<=r):
    mid=(r+l)//2
    s=0
    for i in box[:mid+1]:
        s+=i[1]
    if s>=d:
        ans=mid
        r=mid-1
    else:
        l=mid+1

print(box[ans][0])
print(start-time.time())