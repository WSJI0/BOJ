'''
19542번
전단지 돌리기
'''

import sys
from collections import deque
input=sys.stdin.readline

n, s, d=map(int, input().split())
graph={}
for _ in range(n-1):
    x, y=map(int, input().split())
    if x not in graph: graph[x]=deque()
    if y not in graph: graph[y]=deque()
    graph[x].append(y)
    graph[y].append(x)

visited={}
def makeDepth(node, pre):
    visited[node]=makeDepth()

print(max(ans*2-2, 0))