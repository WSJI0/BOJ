'''
11050번
이항 계수 1
'''

n, k=map(int,input().split())

def fac(n):
    val=1
    for i in range(1,n+1):
        val*=i
    return val

print(fac(n)//(fac(k)*fac(n-k)))