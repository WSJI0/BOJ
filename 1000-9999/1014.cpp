// 1014번 컨닝

#include <bits/stdc++.h>
using namespace std;

int t, n, m, dp[11][11], ans=0;
char board[11][11];

int solve(int y, int x){
    if(dp[y][x]!=0) return dp[y][x];
 
    if(y>2) dp[y][x]+=solve(y-2, x);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>t;
    while(t--){
        memset(dp, 0, sizeof(dp)); ans=0;

        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) cin>>board[i][j];
        }

        for(int i=0; i<m; i++) 
            if(board[0][i]=='.') dp[0][i]=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) solve(i, j);
        }

        cout<<ans<<"\n";
    }
}