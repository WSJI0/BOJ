//2169 로봇 조종하기 (미완성)

#include <bits/stdc++.h>
using namespace std;

int n, m, board[1001][1001], dp[1001][1001];
int mv[3][2]={{1, 0}, {0, 1}, {0, -1}};

int solve(int y, int x, int d){
    if(board[y][x]==101) return dp[y][x];
    for(int j=0; j<3; j++){
        int vy=-mv[j][0]+y;
        int vx=-mv[j][1]+x;
        if(0<=vx && vx<m && 0<=vy && vy<n && d!=mv[j][1]){
            dp[y][x]=max(dp[y][x], solve(vy, vx, -mv[j][1])+board[y][x]);
        }
    }
    board[y][x]=101;
    return dp[y][x];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }
    dp[0][0]=board[0][0]; board[0][0]=101;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            solve(i, j, 0);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<dp[i][j]<<" ";
        }cout<<"\n";
    }
}