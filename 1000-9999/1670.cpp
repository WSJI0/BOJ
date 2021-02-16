// 1670번 정상 회담 2

#include <bits/stdc++.h>
using namespace std;
#define mod 987654321

long long n, dp[10001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    dp[0]=1; dp[2]=1; dp[4]=2;
    for(int i=6; i<=10000; i+=2){
        for(int j=0; j<=i-2; j+=2){
            dp[i]=(dp[i]+dp[j]*dp[i-j-2])%mod;
        }
    }

    cin>>n;
    cout<<dp[n]<<"\n";
}