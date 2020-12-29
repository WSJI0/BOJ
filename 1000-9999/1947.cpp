//1947 선물 전달

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000000

long long dp[1000001];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    dp[2]=1; dp[3]=2;
    for(int i=4; i<=n; i++){
        dp[i]=(i-1)*(dp[i-2]+dp[i-1])%mod;
    }
    cout<<dp[n]%mod<<"\n";
}