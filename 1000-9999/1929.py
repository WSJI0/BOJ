'''
1929번
소수 구하기
'''

m,n=list(map(int,input().split()))

def check(n):
    for i2 in range(2,int(n**0.5)+1):
        if n%i2==0:
            return 0
    return 1

for i in range(m,n+1):
    if i!=1:
        if check(i)==1:
            print(i)