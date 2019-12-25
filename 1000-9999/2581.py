'''
2581번
소수
'''

m=int(input())
n=int(input())

def check(n):
    for i2 in range(2,n):
        if n%i2==0:
            return 0
    return 1

s=0
mm=10000
for i in range(m,n+1):
    if i!=1:
        if check(i)==1:
            s+=i
            if mm>i:
                mm=i
if s!=0:
    print(s)
    print(mm)
else:
    print(-1)