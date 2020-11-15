//11404번 플로이드

#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b, c;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) dp[i][j]=987654321;
    }

    while(m--){
        cin>>a>>b>>c;
        dp[a][b]=min(dp[a][b], c);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dp[i][j]>dp[i][k]+dp[k][j])
                    dp[i][j]=dp[i][k]+dp[k][j];
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j || dp[i][j]==987654321){
                cout<<"0 ";
                continue;
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}