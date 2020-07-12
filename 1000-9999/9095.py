'''
9095번
1, 2, 3 더하기
'''

import sys
input=sys.stdin.readline

t=int(input())

for _ in range(t):
    n=int(input())
    dp=[n]
    cnt=0
    while True:
        a=[]
        for i in dp:
            a.extend([i-1, i-2, i-3])
        dp=a

        b=[]
        for i in dp:
            if i==0:
                cnt+=1
            elif i>0:
                b.append(i)
        if len(dp)==0: break
        dp=b
    print(cnt)