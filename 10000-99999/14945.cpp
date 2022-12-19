// 14945번 불장난

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, dp[101][101][2];

int solve(int cur, int x, int a){
    if(cur==1) return 1;
    if(dp[cur][x][a]!=-1) return dp[cur][x][a];
    ll res=solve(cur-1, x, a);
    if(x!=0) res+=solve(cur-1, x-1, a);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    ll ans=0;
    for(int i=0; i<n; i++) ans+=solve(n, i, 0)+solve(n, i, 1);
}