'''
1463번
1로 만들기
'''

import sys

n=int(sys.stdin.readline())
arr=[n]
co=0

while True:
    if n==1:
        print(co)
        break
    
    a=[]
    for i in arr:
        a.append(i-1)
        if i%3==0:
            a.append(i//3)
        if i%2==0:
            a.append(i//2)
    arr=a
    co+=1
    if 1 in arr:
        print(co)
        break