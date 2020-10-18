n, l, r=map(int, input().split()); l-=1
A=list(map(int, input().split()))
a=[]
for i in range(len(A)):
    ok=True
    for j in range(len(A)):
        if i==j: continue
        if A[i]%A[j]==0: ok=False
    if ok: a.append(A[i])

def GCD(a, b):
    return b if a%b==0 else GCD(b, a%b)

def LCM(a, b):
    return (a*b)//GCD(a, b)

b=[]; c=[]
def backT(lcm, choose, cur):
    global b, c
    if cur==len(a):
        if choose==len(a) and cur!=2:
            c.append(lcm)
        elif choose>=2:
            b.append(lcm)
        return
    backT(LCM(lcm, a[cur]), choose+1, cur+1)
    backT(lcm, choose, cur+1)
backT(1, 0, 0)
b=list(set(b))
c=list(set(c))

ans=0
for i in range(len(a)):
    ans+=r//a[i]
for i in range(len(b)):
    ans-=r//b[i]
for i in range(len(c)):
    ans+=r//c[i]
for i in range(len(a)):
    ans-=l//a[i]
for i in range(len(b)):
    ans+=l//b[i]
for i in range(len(c)):
    ans-=l//c[i]

print(ans)