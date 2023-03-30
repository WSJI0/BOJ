#include <bits/stdc++.h>
using namespace std;

int n, m, k, dp[101][101][81];
char board[101][101];
string s;
int mv[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int solve(int cy, int cx, int l){
    if(dp[cy][cx][l]) return dp[cy][cx][l];
    if(l==s.length()+1) return 1;

    for(int i=0; i<4; i++){
        bool ok=true;
        for(int j=1; j<=k; j++){
            int my=cy+(mv[i][0]*j);
            int mx=cx+(mv[i][1]*j);
            if(0<=my && my<n && 0<=mx && mx<m){
                if(board[my][mx]==s[l]){
                    dp[cy][cx][l]=max(dp[cy][cx][l], dp[my][mx][l+1]+solve(my, mx, l+1));
                }
            }
        }
    } return dp[cy][cx][l];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>board[i][j];
    } cin>>s;

    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) ans+=solve(i, j, 1);
    }
    cout<<ans<<"\n";
}W