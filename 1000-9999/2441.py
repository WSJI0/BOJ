'''
2441번
별 찍기 -4
'''

n=int(input())
for i in range(n,0,-1):
    print(" "*(n-i)+"*"*i)
