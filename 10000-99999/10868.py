'''
10868번
최솟값
'''

import sys
input=sys.stdin.readline

def init(start, end, node):
    if start==end:
        tree[node]=a[start]
        return tree[node]

    mid=(start+end)//2
    tree[node]=min(init(start, mid, node*2),init(mid+1, end, node*2+1))
    return tree[node]

def findMin(start, end, node, left, right):
    if left>end or right<start: return 9999999999
    if left<=start and end<=right: return tree[node]
    mid=(start+end)//2
    return min(findMin(start, mid, node*2, left, right), findMin(mid+1, end, node*2+1, left, right))

n, m=map(int, input().split())
a=[]
tree=[9999999999]*(4*n)
for _ in range(n): a.append(int(input()))
init(0, n-1, 1)
for _ in range(m):
    s, e=map(int, input().split())
    print(findMin(0, n-1, 1, s-1, e-1))