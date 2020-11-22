#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int dp[1001][1001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    while(1){
        cin>>n>>m;
        if(n==0 && m==0) break;
        
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                cin>>board[i][j];
        }
        for(int y=0; y<n; y++){
            dp[y][0]=board[y][0];
            for(int x=0; x<m; x++){
                if(board[y][x]==1){
                    if(y>0 && x>0 && board[y-1][x] && board[y-1][x-1] && board[y][x-1]) 
                        dp[y][x]=min(min(dp[y-1][x], dp[y-1][x-1]), dp[y][x-1])+1;
                    else dp[y][x]=1;
                }
                else dp[y][x]=0;
            }
            int res=0;
            for(int i=0; i<m; i++) res=max(res, dp[y][i]);
            ans=max(ans, res);
        }
        cout<<ans<<"\n";
    }
}