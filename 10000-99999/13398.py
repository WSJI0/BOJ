'''
13398번
연속합 2
'''

import sys

n=int(sys.stdin.readline())
a=list(map(int, sys.stdin.readline().split()))

if n==1:
    print(a[0])
else:
    stack=[]
    m=[]
    M=0
    for i in a:
        if i>=0:
            if len(stack)==0:
                stack.append(i)
            else:
                if stack[-1]>=0:
                    stack[-1]+=i
                    M-=1
                else:
                    stack.append(i)
        else:
            stack.append(i)
            m.append(M)
        M+=1

    maxValue=0
    toDelete=0
    for j in m:
        if j!=0 and j!=len(stack)-1:
            if stack[j-1]+stack[j+1]>maxValue:
                maxValue=stack[j-1]+stack[j+1]
                toDelete=j    

    if toDelete!=0:
        stack.pop(toDelete)
        toSum=stack.pop(toDelete)
        stack[toDelete-1]+=toSum

    s=[]
    for k in stack:
        if k>=0:
            s.append(k)
        else:
            if len(s)==0:
                s.append(k)
            else:
                if s[-1]<0:
                    s[-1]+=k
                else:
                    s.append(k)

    print(s)
    last=len(s)-1
    ans=0
    if len(s)%2==0:
        if s[0]>0:
            for t in range(last, -1, -2):
                ans=max(ans, sum(s[:t]))
        else:
            for t in range(last, 0, -2):
                print(s[:t])
                ans=max(ans, sum(s[1:t]))

    else:
        if s[0]>0:
            for t in range(last, -1, -2):
                ans=max(ans, sum(s[:t]))
        else:
            for t in range(last, 0, -2):
                ans=max(ans, sum(s[1:t]))

    print(ans)