'''
1026번
보물
'''

n=int(input())

A=list(map(int,input().split()))
B=list(map(int,input().split()))
A.sort()
B.sort(reverse=True)

sum=0
for i in range(n):
    sum+=A[i]*B[i]
print(sum)