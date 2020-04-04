'''
15649번
N과 M (1)
'''

n,m=map(int,input().split())
 
check=[0]*(n+1)
t=[0]*m
 
def make(n, m, l):
    if l==m:
        for i in range(m):
            print (t[i], end=' ')
        print()            
        return

    for i in range(1, n+1):
        if check[i]==0:
            t[l]=i
            check[i]=1
            make(n,m,l+1)
            check[i]=0

make(n,m,0)