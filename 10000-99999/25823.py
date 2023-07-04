m=int(input())
fac=[1, 1]; mod=1000000007

for i in range(2, 400002):
    fac.append((fac[-1]*i)%mod)

def modPow(a, n, p):
    if n==0: return 1
    res=modPow(a*a%p, n//2, p)
    if n&1: res=res*a%p
    return res

def nCr(n, k):
    return fac[n]*modPow(fac[k]*fac[n-k], mod-2, mod)%mod

ans=0
for i in range(3, m+1):
    ans=(ans+nCr(i*2, i))%mod

print(ans)