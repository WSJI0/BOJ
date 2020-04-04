'''
2522번
별 찍기 - 12
'''

n=int(input())

for i in range(1,n+1):
    print(" "*(n-i)+"*"*i)
for j in range(n):
    print(" "*(j+1)+"*"*(n-j-1))