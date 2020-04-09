'''
2609번
최대공약수와 최소공배수
'''

n, m=map(int,input().split())

MAX=max(n,m)
MIN=min(n,m)

for i in range(1, MAX+1):
    if n%i==0 and m%i==0:
        GCD=i

for j in range(MAX,n*m+1,MAX):
    if j%n==0 and j%m==0:
        LCM=j
        break

print(GCD)
print(LCM)