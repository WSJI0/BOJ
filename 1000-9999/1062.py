'''
1062번
가르침
'''

import sys

n, k=map(int,sys.stdin.readline().split())
word=[]
learn=[1,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0]
alpha=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
maxN=0

def teach(s,c):
    global n, k, word, alpha, maxN
    cnt=0
    if c==k:
        for j in word:
            cnt2=1
            for l in j:              
                if learn[alpha.index(l)]==0:
                    cnt2=0
                    break
            if cnt2==1:
                cnt+=1
        maxN=max(maxN,cnt)       

    else:
        for i in range(s, 26):
            if learn[i]==0:
                learn[i]=1
                teach(i,c+1)
                learn[i]=0


for _ in range(n):
    w=input()
    w=w.replace('a','')
    w=w.replace('c','')
    w=w.replace('i','')
    w=w.replace('n','')
    w=w.replace('t','')
    word.append(w)

if k<5:
    print(0)
elif k==5:
    cn=0
    for t in word:
        if t=='':
            cn+=1
    print(cn)
else:
    k-=5
    teach(0,0)
    print(maxN)