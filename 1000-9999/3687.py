'''
3687번
성냥개비
'''

'''
# DP

import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n=int(input())
    match=[6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6]
    dp=[]; ansMin=99999999999999999999999999999999999999999999999999
    for i in range(1, 10):
        if match[i]<n: dp.append([str(i), n-match[i]])
        elif match[i]==n:
            ansMin=min(ansMin, i)
    ansMax='7'*(n%2)+'1'*(n//2-(n%2))

    while dp:
        a=[]
        for i in dp:
            for j in [0, 1, 2, 4, 7, 8]:
                if match[j]<i[1]:
                    a.append([i[0]+str(j), i[1]-match[j]])
                elif match[j]==i[1]:
                    ansMin=min(ansMin, int(i[0]+str(j)))
        dp=a
    print(ansMin, ansMax)

'''

import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n=int(input())
    match=[6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
    ans=[0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22]
    ansMax='7'*(n%2)+'1'*(n//2-(n%2))
    if n<=10: 
        print(ans[n], ansMax)
        continue

    ansMin=''
    while n>0:
        n-=7
        if n>=0: ansMin+='8'
        else: n+=7; break

    small={6:6, 2:1, 5:2}
    if n in small: ansMin=str(small[n])+ansMin
    else: 
        if n==1: ansMin='10'+ansMin[1:]
        elif n==3: ansMin='200'+ansMin[2:]
        elif n==4: ansMin='20'+ansMin[1:]

    print(ansMin, ansMax)