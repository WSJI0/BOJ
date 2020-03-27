'''
2446번
별 찍기 - 9
'''

n=int(input())

for i in range(n-1,-1,-1):
    print(" "*(n-i-1)+"*"*((i+1)*2-1))

for j in range(1,n):
    print(" "*(n-j-1)+"*"*((j+1)*2-1))