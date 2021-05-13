#include <bits/stdc++.h>
using namespace std;

int t, n, tri[401][1200], ans, dp[401][1200];

int solve(int line, int x){
    if(line>=n) return 0;
    if(dp[line][x]!=-1) return dp[line][x];
    ans=max(ans, tri[line][x]);
    if(line==n-1) return dp[line][x]=tri[line][x];
    dp[line][x]=tri[line][x]+solve(line+1, x)+solve(line+1, x+2)+tri[line+1][x+1]-solve(line+2, x+2); 
    ans=max(ans, dp[line][x]);
    return dp[line][x];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while(++t){
        cin>>n;
        if(n==0) break;

        ans=INT_MIN;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=0; j<i*2+1; j++) cin>>tri[i][j];
        }

        solve(0, 0);
        cout<<t<<". "<<ans<<"\n";
    }
}