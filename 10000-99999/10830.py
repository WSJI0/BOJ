n, b=map(int, input().split())

matrix=[]
for _ in range(n):
    matrix.append(list(map(int, input().split())))

for i in range(n):
    for j in range(n):
        matrix[i][j]=matrix[i][j]%1000

def cal(m1, m2):
    res=[[0 for _ in range(len(m1))] for _ in range(len(m1))]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                res[i][j]=(res[i][j]+m1[i][k]*m2[k][j])%1000
    return res

def solve(s):
    if s==1: return matrix
    tmp=solve(s//2)
    if s%2==0:
        return cal(tmp, tmp)
    return cal(cal(tmp, tmp), matrix)

ans=solve(b)
for i in ans:
    print(*i)