//2169 로봇 조종하기

#include <bits/stdc++.h>
using namespace std;
#define INF -200000000

int n, m, board[1001][1001], dp[3][1001][1001];
bool visited[1001][1001];
int mov[3][2]={
    {0, -1}, {-1, 0}, {0, 1}
};

int solve(int y, int x, int pre){
    if(y==0 && x==0) return board[0][0];

    int& ret=dp[pre][y][x];
    if(ret!=INF) return ret;

    visited[y][x]=1;

    for(int v=0; v<3; v++){
        int my=y+mov[v][0], mx=x+mov[v][1];
        if(0<=my && 0<=mx && mx<m){
            if(!visited[my][mx]) ret=max(ret, solve(my, mx, v)+board[y][x]);
        }
    }

    visited[y][x]=0;
    return ret;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            for(int k=0; k<3; k++) dp[k][i][j]=INF;
        }
    }
    
    cout<<solve(n-1, m-1, 0)<<"\n";
}