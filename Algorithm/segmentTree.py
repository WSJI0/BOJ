'''
세그먼트 트리
https://velog.io/@kineqwer1123/Python%EB%B0%B1%EC%A4%80-2042-%EC%84%B8%EA%B7%B8%EB%A8%BC%ED%8A%B8-%ED%8A%B8%EB%A6%AC 참고함
'''

def init(start, end, node):
    if start==end:
        tree[node]=a[start]
        return tree[node]

    mid=(start+end)//2
    tree[node]=min(init(start, mid, node*2),init(mid+1, end, node*2+1))
    return tree[node]

def summit(start, end, node, left, right):
    if left>end or right<start: return 0
    if left<=start and end<=right: return tree[node]
    mid=(start+end)//2
    return min(summit(start, mid, node*2, left, right), summit(mid+1, end, node*2+1, left, right))

def update(start, end, node, index, dif):
    if index<start or index>end: return
    tree[node]=min(tree[node], dif)
    if start==end: return
    mid(start+end)//2
    update(start, mid, node*2, index, dif)
    update(mid+1, end, node*2+1, index, dif)

n=10
a=[]
tree=[0]*(4*n)
for i in range(n):
    a.append(i)

init(0, n-1, 1)
print(tree)