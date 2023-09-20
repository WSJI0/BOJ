#include <bits/stdc++.h>
using namespace std;

int n, a[1001], dp[1001], ans=1;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[j]>a[i]){
                dp[i]=max(dp[i], dp[j]);
            }
        } dp[i]++;
        ans=max(ans, dp[i]);
    }
    cout<<ans<<"\n";
}