n=int(input())
a=list(map(int, input().split()))

u=0; d=0; mu=0; md=0
for i in range(n-1):
    if a[i+1]>a[i]: 
        u+=1
        d=0
    elif a[i+1]<a[i]:
        u=0
        d+=1
    mu=max(mu, u)
    md=max(md, d)

print(max(mu, md)+1)