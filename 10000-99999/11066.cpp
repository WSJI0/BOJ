#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int t, k, c[501];
int psum[502];
ll dp[501][501];

ll solve(int l, int r){
    if(l==r) return 0;
    if(l+1==r) return c[l]+c[r];
    if(dp[l][r]!=0) return dp[l][r];

    dp[l][r]=LLONG_MAX;
    for(int i=l; i<r; i++){
        dp[l][r]=min(dp[l][r], (psum[r+1]-psum[l])+solve(l, i)+solve(i+1, r));
    }
    return dp[l][r];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        cin>>k;
        for(int i=0; i<k; i++) cin>>c[i];
        for(int i=1; i<=k; i++) psum[i]=c[i-1]+psum[i-1];

        cout<<solve(0, k-1)<<"\n";
    }
}