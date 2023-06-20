#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n, m, c;
int w[17][17], ca[1002], cb[1002];
ll dp[1002][1002];

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m>>c;
    for(int i=1; i<=c; i++){
        for(int j=1; j<=c; j++) cin>>w[i][j];
    }
    for(int i=1; i<=n; i++) cin>>ca[i];
    for(int i=1; i<=m; i++) cin>>cb[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j]=max(dp[i][j-1], dp[i-1][j-1]+w[ca[i]][cb[j]]);
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
        }
    } cout<<dp[n][m]<<"\n";
}