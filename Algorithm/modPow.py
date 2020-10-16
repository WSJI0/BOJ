def modPow(a, n, l):
    if n==0: return 1
    res=modPow(a*a%l, n//2, l)
    if n&1: res=res*a%l
    return res