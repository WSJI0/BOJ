//14938 서강그라운드

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, r, a, b, l;
    cin>>n>>m>>r;
    vector<int> t(n+1);
    for(int i=1; i<=n; i++) cin>>t[i];
    int dp[101][101];
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            dp[i][j]=987654321;
        }
    }

    for(int i=0; i<r; i++){
        cin>>a>>b>>l;
        dp[a][b]=l;
        dp[b][a]=l;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dp[i][j]>dp[i][k]+dp[k][j])
                    dp[i][j]=dp[i][k]+dp[k][j];
            }
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        int res=t[i];
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            if(dp[i][j]<=m) res+=t[j];
        }
        ans=max(ans, res);
    }
    cout<<ans<<"\n";
}