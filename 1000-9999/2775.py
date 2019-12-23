'''
2775번
부녀회장이 될테야
'''


testCase=int(input())

def fac(n):
    t2=1
    for i3 in range(1,n+1):
        t2*=i3
    return t2

for i in range(testCase):
    k=int(input())
    n=int(input())

    t=1
    for i2 in range(k+2,n+k+1):
        t*=i2;
    print(t//fac(n-1))