//2602번 돌다리 건너기

#include <bits/stdc++.h>
using namespace std;

long long int dp[2][101][21];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string p, board[2];
    cin>>p>>board[0]>>board[1];

    int l=board[0].length();
    int r=p.length();

    for(int i=0; i<l; i++){
        for(int j=0; j<2; j++){
            if(board[j][i]==p[0]) dp[j][i][0]=1;
        }
    }

    for(int i=0; i<l; i++){
        for(int j=0; j<2; j++){
            for(int k=1; k<r; k++){
                for(int m=0; m<i; m++){
                    if(board[j][i]==p[k] && board[abs(j-1)][m]==p[k-1])
                        dp[j][i][k]+=dp[abs(j-1)][m][k-1];
                }
            }
        }
    }
    long long int ans=0;
    for(int i=0; i<2; i++){
        for(int j=0; j<l; j++){
            if(board[i][j]==p[p.length()-1]) ans+=dp[i][j][p.length()-1];
        }
    }

    cout<<ans<<"\n";
}