'''
3649번
로봇 프로젝트
'''

import sys
    

x=int(sys.stdin.readline())*10000000
n=int(sys.stdin.readline())

block=[]
for _ in range(n):
    b=int(sys.stdin.readline())
    block.append(b) 

block.sort()
    
left=0
right=n-1
while left<right:
    blocks=block[left]+block[right]
    if blocks==x:
        break
    elif blocks<x:
        left+=1
    else:
        right-=1
    
if left>=right:
    print("danger")
else:
    print("yes", block[left], block[right])