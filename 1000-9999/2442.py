'''
2442번
별 찍기 - 5
'''

n=int(input())

for i in range(1,n+1):
    print(" "*(n-i)+"*"*(i*2-1))