// 8895번 막대 배치 (미완성)

#include <bits/stdc++.h>
using namespace std;

int t, n, l, r, dp[21][21][21];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    dp[1][1][1]=1;
    for(int i=2; i<=20; i++){
        for(int j=1; j<=i; j++){
            for(int k=1; k<=i; k++){
                dp[i][j][k]=dp[i-1][j][k];
            }
        }
    }

    cin>>t;
    while(t--){
        cin>>n>>l>>r;
        cout<<dp[n][l][r]<<"\n";`1
    }
}