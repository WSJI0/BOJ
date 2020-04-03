'''
15652번
N과 M (4)
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
            for j in range(i):
                check[j]=1
            make(n,m,l+1)
            for k in range(i):
                check[k]=0

make(n,m,0)