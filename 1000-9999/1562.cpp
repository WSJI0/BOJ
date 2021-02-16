// 1562번 계단 수 (미완성)

#include <bits/stdc++.h>
using namespace std;

int n, dp[10][101];

int solve(int s, int n){
    if(dp[s][n]!=-1) return dp[s][n];

}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<10; i++) dp[0][i]=0;
    dp[10]=1;

    cin>>n;
    cout<<solve(0, n)<<"\n";
}