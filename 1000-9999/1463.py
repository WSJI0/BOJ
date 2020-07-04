'''
1463번
1로 만들기
'''

import sys
input=sys.stdin.readline

n=int(input())

cnt=0
num=[n]
while True:
    
    if n==1:
        print(0)
        break
    
    a=[]
    for i in range(len(num)):
        a.append(num[i]-1)
        if num[i]%3==0:
            a.append(num[i]//3)
        if num[i]%2==0:
            a.append(num[i]//2)

    num=a
    cnt+=1
    if 1 in num:
        print(cnt)
        break
    