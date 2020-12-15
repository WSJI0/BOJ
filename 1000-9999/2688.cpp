// 2688 줄어들지 않아

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[10][65];

ll solve(int s, int n){
    if(dp[s][n]!=-1) return dp[s][n];
    dp[s][n]=0;
    for(int i=s; i<10; i++){
        dp[s][n]+=solve(i, n-1);
    }
    return dp[s][n];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin>>t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin>>n;
        ll ans=0;
        for(int i=0; i<10; i++) dp[i][1]=1;
        for(int i=0; i<10; i++) ans+=solve(i, n);
        cout<<ans<<"\n";
    }
}