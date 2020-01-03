n,m=list(map(int,input().split()))

card=list(map(int,input().split()))

sum=[]
dp=[]

for j2 in range(max(card)+1):
    dp.append([])
    for j3 in range(max(card)+1):
        dp[j2].append([])
        for j4 in range(max(card)+1):
            dp[j2][j3].append(0)

for i in range(n):
    for j in range(i+1,n):
        for k in range(j+1,n):
            if dp[card[i]][card[j]][card[k]]==0:
                s=card[i]+card[j]+card[k]
                sum.append(s)
                dp[card[i]][card[j]][card[k]]=s
            else:
                sum.append(dp[card[i]][card[j]][card[k]])

for i2 in range(m,1,-1):
    if i2 in sum:
        print(i2)
        break