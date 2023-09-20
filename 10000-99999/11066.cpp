#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll t, k, a[501], dp[501][501], p[502];

ll solve(int l, int r){
    if(l==r) return 0;
    if(l+1==r) return a[l]+a[r];
    if(dp[l][r]) return dp[l][r];

    dp[l][r]=LLONG_MAX;
    for(int i=l; i<r; i++){
        dp[l][r]=min(dp[l][r], solve(l, i)+solve(i+1, r));
    } dp[l][r]+=p[r+1]-p[l];

    return dp[l][r];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        memset(dp, 0, sizeof(dp));

        cin>>k;
        for(int i=0; i<k; i++) cin>>a[i];
        p[1]=a[0];
        for(int i=1; i<k; i++) p[i+1]=p[i]+a[i];
        cout<<solve(0, k-1)<<"\n";
    }
}