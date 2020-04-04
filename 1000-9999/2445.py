'''
2445번
별 찍기 - 8
'''

n=int(input())

for j in range(n,0,-1):
    print("*"*(n-j+1)+" "*((j-1)*2), end='')
    print("*"*(n-j+1))
for i in range(1,n):
    print("*"*(n-i)+" "*(i*2), end='')
    print("*"*(n-i))