'''
4342번
유클리드 게임

미완성
'''

import sys
input=sys.stdin.readline

def euclid(a, b):
    cnt=0
    if b>a: a,b=b,a
    while b:
        temp=a
        a=b
        b=temp%b
        cnt+=1
        print(a,b)
    return cnt

while True:
    a, b=map(int, input().split())
    if a==b==0: break
    
    print(euclid(a, b))