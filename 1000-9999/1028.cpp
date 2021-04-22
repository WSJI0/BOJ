// 1028번 다이아몬드 광산

#include <bits/stdc++.h>
using namespace std;

int r, c, dp[752][752][4], board[752][752], ans;

int main(void){
    
    scanf("%d %d", &r, &c);
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++) scanf("%1d", &board[i][j]);
    }

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            int ii=r-i+1;
            if(board[i][j]){
                dp[i][j][0]=dp[i-1][j-1][0]+1;
                dp[i][j][1]=dp[i-1][j+1][1]+1;
            }
            if(board[ii][j]){
                dp[ii][j][2]=dp[ii+1][j+1][2]+1;
                dp[ii][j][3]=dp[ii+1][j-1][3]+1;
            }
        }
    }

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            int a=min(dp[i][j][2], dp[i][j][3]);
            int b=min(dp[i][j][1], dp[i][j][2]);
            for(int k=1; k<=a; k++){
                if((k-1)*2+i>r) break;
                if(dp[(k-1)*2+i][j][0]>=k && dp[(k-1)*2+i][j][1]>=k){
                    ans=max(ans, k);
                }
            }
            for(int k=1; k<=b; k++){
                if((k-1)*2+j>c) break;
                if(dp[i][(k-1)*2+j][0]>=k && dp[i][(k-1)*2+j][3]>=k){
                    ans=max(ans, k);
                }
            }
        }
    }
    
    printf("%d", ans);
}