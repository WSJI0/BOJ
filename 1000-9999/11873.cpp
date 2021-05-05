// 11873번 최대 직사각형(미완성)

#include <bits/stdc++.h>
using namespace std;

int n, m, board[1002][1002], dp[1002][1002][2], ans;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while(1){
        cin>>n>>m;
        if(n==0 && m==0) break;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++) cin>>board[i][j];
        }

        ans=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(board[i][j]){
                    if(board[i-1][j]) dp[i][j][0]=dp[i-1][j][0];
                    if(board[i][j-1]) dp[i][j][1]=dp[i][j-1][1];
                }
            }
        }

    }
}