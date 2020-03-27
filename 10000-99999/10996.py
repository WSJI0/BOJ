'''
10996번
별 찍기 - 21
'''

n=int(input())

for i in range(n*2):
    for j in range(n):
        if i%2==0 and j%2==0:
            print("* ",end='')
        if i%2==1 and j%2==1:
            print(" *",end='')
    print()