//1695번 팰린드롬 만들기

#include <bits/stdc++.h>
using namespace std;

int a[5001];
int dp[5001][5001];

int solve(int l, int r){
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    if(a[l]==a[r]) return dp[l][r]=solve(l+1, r-1);
    else return dp[l][r]=min(solve(l+1, r), solve(l, r-1))+1;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<solve(0, n-1)<<"\n";
}