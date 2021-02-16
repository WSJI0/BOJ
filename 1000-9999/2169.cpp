//2169 로봇 조종하기

#include <bits/stdc++.h>
using namespace std;
#define INF -200000000

int n, m, board[1001][1001], dp[1001][1001];
bool visited[1001][1001];
int mov[3][2]={
    {0, -1}, {-1, 0}, {0, 1}
};

int solve(int y, int x){
    if(dp[y][x]!=INF) return dp[y][x];

    int& ret=dp[y][x];
    for(auto v:mov){
        int my=y+v[0], mx=x+v[1];
        if(0<=my && 0<=mx){
            ret=max(ret, solve(my, mx)+board[y][x]);
        }
    }
    return ret;
}

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            dp[i][j]=INF;
        }
    }
    
    dp[0][0]=board[0][0];
    cout<<solve(n-1, m-1)<<"\n";

    print();
}