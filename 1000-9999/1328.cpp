#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int

int n, l, r;
int dp[101][101][101][101], v[101];

int solve(int l, int lm, int r, int rm){
    if(dp[l][lm][r][rm]) return dp[l][lm][r][rm];
    if(l==0 && r==0){
        
    }

    int& ret=dp[l][lm][r][rm];

    for(int i=lm; i<=n; i++){
        for(int j=rm; j<=n; j++){
            if(l>0) l--;
            if(r>0) r--;
            ret=(ret+solve(l, i, r, j))%mod;
        }
    }

    return ret;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>l>>r;
    cout<<solve(l, 0, r, 0)<<"\n";
}