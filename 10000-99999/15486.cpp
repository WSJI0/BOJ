#include <bits/stdc++.h>
using namespace std;

int n, dp[1500001], ans;
pair<int, int> tp[1500001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++) cin>>tp[i].first>>tp[i].second;

    for(int i=1; i<=n; i++){
        dp[i]=dp[i-1];
        for(int j=0; j<=50; j++){
            if(i-j<=0) break;
            if(tp[i-j].first==j+1) 
                dp[i]=max(dp[i], dp[i-j-1]+tp[i-j].second);
        } 
        ans=max(ans, dp[i]);
    }
    cout<<ans<<"\n";
}