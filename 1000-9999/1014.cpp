// 1014번 컨닝

#include <bits/stdc++.h>
using namespace std;

int t, n, m, dp[11][11], ans=0;
int mov[10][2]={
    {0, -2}, {-1, -2}, {-2, -2}, {-2, -1}, {-2, 0}, {-2, 1}, {-2, 2}, {-1, 2}, {0, 2}, {-1, 0}
};
char board[11][11];

int solve(int y, int x){
    if(board[y][x]=='x') return 0;
    if(dp[y][x]!=0) return dp[y][x];
    
    int& ret=dp[y][x]; ret=1;
    for(auto v:mov){
        int my=v[0]+y;
        int mx=v[1]+x;
        if(my>=0 && my<n && mx>=0 && mx<m){
            ret=max(ret, solve(my, mx)+1);
        }
    }
    return ret;
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

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) cout<<board[i][j];
            cout<<"\n";
        }

        for(int i=0; i<m; i++) 
            if(board[0][i]=='.') dp[0][i]=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) ans=max(ans, solve(i, j));
        }

        cout<<"ANS"<<ans<<"\n";
    }
}