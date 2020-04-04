'''
2443번
별 찍기 - 6
'''

n=int(input())

for i in range(n,0,-1):
    print(" "*(n-i)+"*"*(i*2-1))