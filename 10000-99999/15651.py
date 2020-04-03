'''
15651번
N과 M (3)
'''

n,m=map(int,input().split())
 
t=[0]*m
 
def make(n, m, l):
    if l==m:
        for i in range(m):
            print (t[i], end=' ')
        print()            
        return

    for i in range(1, n+1):
        t[l]=i
        make(n,m,l+1)

make(n,m,0)