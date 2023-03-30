#include <bits/stdc++.h>
using namespace std;
#define mod 1000000003

int n, k;
int dp[1002][1002];

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>k;

    for(int i=0; i<=n; i++) dp[i][0]=1;
    dp[1][1]=1;

    for(int i=2; i<n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j]=(dp[i-2][j-1]+dp[i-1][j])%mod;
        }
    }
    dp[n][k]=(dp[n-1][k]+dp[n-3][k-1])%mod;
    cout<<dp[n][k]<<"\n";
}