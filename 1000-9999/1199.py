'''
1199번
오일러 회로

(미완성)
'''

import sys
input=sys.stdin.readline

n=int(input())
graph=[]
no=False
for i in range(n):
    graph.append(list(map(int, input().split())))
    if sum(graph[-1])%2==1: no=True

visited={}
def dfs(i):


if no: print(-1)
else: dfs(0)