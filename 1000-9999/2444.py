'''
2444번
별 찍기 - 7
'''

n=int(input())

for i in range(1,n):
    print(" "*(n-i)+"*"*(i*2-1))
for j in range(n,0,-1):
    print(" "*(n-j)+"*"*(j*2-1))