#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000000

int n;
ll dp[102][10][1<<10];

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;

    if(n<10){
        cout<<0<<"\n";
        return 0;
    }

    for(int i=1; i<=9; i++) dp[1][i][(1<<10)|(1<<i)]=1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            for(int k=1024; k<2048; k++){
                if(j>0) dp[i][j][k|(1<<j)]+=dp[i-1][j-1][k];
                if(j<9) dp[i][j][k|(1<<j)]+=dp[i-1][j+1][k];
                dp[i][j][k|(1<<j)]%=MOD;
            }
        }
    }

    ll ans=0;
    for(int i=0; i<=9; i++){
        ans=(ans+dp[n][i][2047])%MOD;
    } cout<<ans<<"\n";
}