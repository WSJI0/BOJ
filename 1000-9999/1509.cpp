//1509 팰린드롬 분할 (미완성)

#include <bits/stdc++.h>
using namespace std;

int dp[2001][2001], n, a[2001];

int solve(int l, int r){
    if(l==r) dp[l][r]=1;
    if(l>=r) return 1;
    if(dp[l][r]!=-1) return dp[l][r];

    if(solve(l+1, r-1)==1 && a[l]==a[r]) dp[l][r]=1;
    else dp[l][r]=0;
    return dp[l][r];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            solve(i, j);
        }
    }

    int l, r;
    while
}