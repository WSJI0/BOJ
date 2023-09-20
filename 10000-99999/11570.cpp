#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n, s[2002];
ll dp[2001][2001]; // A가 어디까지 불렀는지, B가 어디까지 불렀는지

ll solve(int a, int b){
    if(dp[a][b]!=-1) return dp[a][b];

    dp[a][b]=LLONG_MAX;
    if(b>a+1) return dp[a][b]=solve(a, b-1)+abs(s[b]-s[b-1]);
    if(a>b+1) return dp[a][b]=solve(a-1, b)+abs(s[a]-s[a-1]);

    if(a>b){
        for(int i=0; i<b; i++) 
            dp[a][b]=min(dp[a][b], solve(i, b)+(i==0? 0:abs(s[a]-s[i])));
    }
    if(b>a){
        for(int i=0; i<a; i++) 
            dp[a][b]=min(dp[a][b], solve(a, i)+(i==0? 0:abs(s[b]-s[i])));
    }

    return dp[a][b];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin>>n;
    for(int i=1; i<=n; i++) cin>>s[i];

    dp[0][0]=dp[0][1]=dp[1][0]=0;
    
    ll ans=LLONG_MAX;
    for(int i=0; i<n; i++){
        ans=min(ans, min(solve(i, n), solve(n, i)));
    } 
    cout<<ans<<"\n";
}