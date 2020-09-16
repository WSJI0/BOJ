'''
1276번
교각 놓기
'''

import sys
input=sys.stdin.readline

n=int(input())

ground=[0]*10001
bridge=[]
for _ in range(n):
    y, x1, x2=map(int, input().split())
    bridge.append([y, x1, x2])
bridge.sort()

ans=0
for i in range(n):
    ans+=bridge[i][0]-ground[bridge[i][1]]
    ans+=bridge[i][0]-ground[bridge[i][2]-1]
    for j in range(bridge[i][1], bridge[i][2]):
        ground[j]=bridge[i][0]

print(ans)