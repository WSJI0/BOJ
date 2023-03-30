a='0'+input()
b='0'+input()

dp=[[0 for _ in range(len(b)+1)] for _ in range(len(a)+1)]

ans=0
for i in range(1, len(a)):
    for j in range(1, len(b)):
        if a[i]==b[j]:
            dp[i][j]=dp[i-1][j-1]+1
        else:
            dp[i][j]=max(dp[i-1][j], dp[i][j-1])

        ans=max(ans, dp[i][j])

print(ans)