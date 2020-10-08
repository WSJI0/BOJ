'''
10868번
최솟값

미완성
'''

import sys
import math
input=sys.stdin.readline

n, m=map(int, input().split())
tree=[]
a=[]
for _ in range(n):
    a.append(int(input()))
tree.append(a)

for _ in range(int(math.log2(n))):
    a=[]
    for j in range(0, len(tree[-1])-len(tree[-1])%2, 2):
        a.append(min(tree[-1][j], tree[-1][j+1]))
    tree.append(a)

print(tree)
for _ in range(m):
    a, b=map(int ,input().split())