'''
3000번
직각 삼각형
'''

import sys
input=sys.stdin.readline

n=int(input())
coor=[]
cx=[0]*100001
cy=[0]*100001
for _ in range(n):
    x, y=map(int, input().split())
    coor.append([x, y])
    cx[x]+=1
    cy[y]+=1

ans=0
for i in range(n):
    ans+=max(0, cy[coor[i][1]]-1)*max(0, cx[coor[i][0]]-1)
    
print(ans)