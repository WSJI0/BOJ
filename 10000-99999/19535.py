'''
19535번
ㄷㄷㄷㅈ
'''

import sys
input=sys.stdin.readline

def nCr(n):
    res=1
    for i in range(n-2, n+1):
        res*=i
    return max(res//6, 1)

n=int(input())
graph={}

for i in range(1, n+1):
    graph[i]=0

node=[]
for _ in range(n-1):
    a, b=map(int, input().split())
    graph[a]+=1
    graph[b]+=1
    node.append([a,b])

d=0
for i in node:
    d+=(graph[i[0]]-1)*(graph[i[1]]-1)

j=0
for i in range(1, n+1):
    if graph[i]>=3:
        j+=nCr(graph[i])

if d==j*3:
    print("DUDUDUNGA")
elif d>j*3:
    print("D")
else:
    print("G")