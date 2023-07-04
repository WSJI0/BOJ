'''
1036번
36진수
'''

import sys
input=sys.stdin.readline

dic=['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']

def change(n):
    res=[]
    if n==0: return '0'
    while n>0:
        res.append(dic[n%36])
        n//=36
    res.reverse()
    return ''.join(res)

def sor(a):
    for i in range(len(a)-1, -1, -1):
        for j in range(i):
            if int(a[j][0], 36)*a[j][1]-int('Z', 36)*a[j][1]>int(a[j+1][0], 36)*a[j+1][1]-int('Z', 36)*a[j+1][1]: 
                a[j],a[j+1]=a[j+1],a[j]
    return a

n=int(input())

ori=[]
val={}
for _ in range(n):
    tmp=input().rstrip()
    idx=0
    for i in range(len(tmp)):
        if tmp[i]!='0': break
        idx+=1
    num=tmp[idx:]
    if num=="": num="0"

    ori.append(num)
    for i in range(len(num)):
        if num[i] not in val: val[num[i]]=0
        val[num[i]]+=pow(36, (len(num)-1-i))

k=int(input())

val=sor(list(val.items()))

o=0
while o<min(k, len(val)):
    for j in range(n):
        ori[j]=ori[j].replace(val[o][0], 'Z')
    o+=1
    
res=0
for i in range(n):
    res+=int(ori[i], 36)

print(change(res))