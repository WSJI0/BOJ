'''
1033번
칵테일
'''

import sys
input=sys.stdin.readline

n=int(input())
ans=[1]*n
graph={}
visited={}

def GCD(a, b):
    return b if a%b==0 else GCD(b, a%b)

def change(a, p, d):
    global visited
    if (a, p) in visited: return
    visited[(a, p)]=True
    ans[a]*=p
    for i in graph[a]:
        if i!=d: 
            change(i, p, a)

for i in range(n): graph[i]=[]
inp=[]
for _ in range(n-1):
    a, b, p, q=map(int, input().split())
    graph[a].append(b); graph[b].append(a)
    inp.append([a, b, p, q])

for i in range(n-1):
    a, b, p, q=inp[i]
    visited={}
    change(a, p, b)
    change(b, q, a)

g=ans[0]
for i in range(n):
    g=GCD(g, ans[i])
for i in range(n): ans[i]//=g
print(*ans)