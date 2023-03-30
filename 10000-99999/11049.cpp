#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n, matrix[501][2];
ll dp[501][501];

ll solve(int l, int r){
    if(l==r) return 0;
    if(l+1==r) return matrix[l][0]*matrix[l][1]*matrix[r][1];
    if(dp[l][r]!=0) return dp[l][r];

    dp[l][r]=LLONG_MAX;
    for(int i=l; i<r; i++){
        dp[l][r]=min(dp[l][r], (matrix[l][0]*matrix[l][1]*matrix[r][1])+solve(l, i)+solve(i+1, r));
    } return dp[l][r];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>matrix[i][0]>>matrix[i][1];
    }

    cout<<solve(0, n-1)<<"\n";
}