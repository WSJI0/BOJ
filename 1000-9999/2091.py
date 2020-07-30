'''
2091번
동전

미완성
'''

import sys
input=sys.stdin.readline

x, a, b, c, d=map(int, input().split())
dp=[x]

i=1
while True:
    dp2=[]
    for i in dp:
        if i-1>=0 and a>0: 
            dp2.append(i-1)
            a-=1
        if i-5>=0 and b>0: 
            dp2.append(i-5)
            b-=1
        if i-10>=0 and c>0: 
            dp2.append(i-10)
            c-=1
        if i-25>=0 and d>0: 
            dp2.append(i-25)
            d-=1
    if dp2.count(0)==len(dp2):
        print(i)
        break
    dp=dp2
    i+=1