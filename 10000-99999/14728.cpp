//14728번 벼락치기

#include <bits/stdc++.h>
using namespace std;

int n, t, study[101][2], dp[101][10001];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>t;
    for(int i=1; i<=n; i++){
        cin>>study[i][0]>>study[i][1];
    }
    for(int i=1; i<=n; i++){
        int time=study[i][0], score=study[i][1];
        for(int j=0; j<=t; j++){
            if(time>j) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j-time]+score, dp[i-1][j]);
        }
    }
    cout<<dp[n][t]<<"\n";
}