n, l, r=map(int, input().split())
a=list(map(int, input().split()))

ans=0
for i in range(l, r+1):
    ok=False
    for j in a:
        if i%j==0: ok=True
    if ok: ans+=1

print(ans)