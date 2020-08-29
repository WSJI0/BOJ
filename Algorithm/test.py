import sys
input=sys.stdin.readline

n=int(input())

dp=[1,2,3,4,5,6,7,8,9]
cnt=0
while True:
    a=[]
    if n==1: break
    for i in range(len(dp)):
        if dp[i]>0:
            a.append(dp[i]-1)
        if dp[i]<9:
            a.append(dp[i]+1)
    dp=a  
    cnt+=1
    if cnt==n-1: break
print(len(dp))