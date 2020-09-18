def f(n):
    q = n // 36
    r = n % 36
    return f(q) + (chr(r+48) if 0 <= r <= 9 else chr(r+55)) if q else chr(r+48) if 0<= r <=9 else chr(r+55)
N = int(input())
c = [0]*36
for i in range(N):
    n = input()
    l = len(n)
    for j in range(l):
        c[int(n[j],36)] += 36**(l-j-1)
K = int(input())
A = [[c[i]*(35-i), i]for i in range(36)]
A.sort()
print(f(sum(map(lambda i: c[A[i][1]] * (A[i][1] if i < 36-K else 35), range(36)))))