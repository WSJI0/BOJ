'''
10775번
공항
'''

import sys
input=sys.stdin.readline

G=int(input())
P=int(input())

parent=[i for i in range(G+1)]
def find(u):
    if(u==parent[u]): return u
    parent[u]=find(parent[u])
    return parent[u]

def merge(u, v):
    u=find(u); v=find(v)
    if(u==v): return
    parent[u]=v

g=[]
for _ in range(P):
    g.append(int(input()))

ans=0
for i in range(P):
    if find(g[i])!=0:
        ans+=1
        merge(find(g[i]), find(g[i])-1)
    else: break
print(ans)