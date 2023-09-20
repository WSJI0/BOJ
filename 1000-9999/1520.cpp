#include <bits/stdc++.h>
using namespace std;

int n, m, board[501][501], dp[501][501];
int mv[4][2]={
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

int solve(int y, int x){
    if(y==0 && x==0) return 1;
    if(dp[y][x]!=-1) return dp[y][x];
    dp[y][x]=0;
    for(auto v:mv){
        int my=y+v[0]; int mx=x+v[1];
        if(0<=my && my<n && 0<=mx && mx<m){
            if(board[my][mx]<=board[y][x]) continue;
            dp[y][x]+=solve(my, mx);
        }
    } return dp[y][x];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }

    cout<<solve(n-1, m-1)<<"\n";
}