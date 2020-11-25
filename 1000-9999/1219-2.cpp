#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m, s, e, a, b, c;
int dp[101][101], vil[101];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>s>>e>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) dp[i][j]=INF;
    }
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        dp[a][b]=c;
    }
    for(int i=0; i<n; i++){
        cin>>vil[i];
        for(int j=0; j<n; j++){
            if(dp[j][i]!=INF) dp[j][i]-=vil[i];
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dp[i][k]==INF || dp[k][j]==INF) continue;
                if(dp[i][j]>dp[i][k]+dp[k][j])
                    dp[i][j]=dp[i][k]+dp[k][j];
            }
        }
    }
    int tmp=dp[s][e];
    cout<<tmp<<"\n";
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dp[i][k]==INF || dp[k][j]==INF) continue;
                if(dp[i][j]>dp[i][k]+dp[k][j])
                    dp[i][j]=dp[i][k]+dp[k][j];
            }
        }
    }
    cout<<dp[s][e]<<"\n";
    if(dp[s][e]==INF) cout<<"gg"<<"\n";
    else if(tmp!=dp[s][e]) cout<<"Gee"<<"\n";
    else cout<<-tmp<<"\n"; 
}