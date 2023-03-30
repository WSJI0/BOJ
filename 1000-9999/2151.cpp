#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n;
char board[51][51];
int dp[51][51];
vector<pair<int, int>> door;

int mv[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void solve(int cy, int cx, int dir, int cur){
    for(int i=0; i<4; i++){
        int my=mv[i][0]+cy;
        int mx=mv[i][1]+cx;
        if(0<=my && my<n && 0<=mx && mx<n){
            if(board[my][mx]=='*') continue;
            if(i==dir){
                if(board[my][mx]=='!' && dp[my][mx]<=cur) continue;
                dp[my][mx]=cur;
                solve(my, mx, dir, cur);
            } else{
                if(board[cy][cx]!='!') continue;
                if(dp[my][mx]<=cur+1) continue;
                dp[my][mx]=cur+1;
                solve(my, mx, i, cur+1);
            }
        }
    } 
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            if(board[i][j]=='#') door.push_back(make_pair(i, j));
        }
    }

    int ans=INF;
    for(int i=0; i<4; i++){
        for(int i=0; i<50; i++){
            for(int j=0; j<50; j++) dp[i][j]=INF;
        }
        dp[door[0].first][door[0].second]=0;
        solve(door[0].first, door[0].second, i, 0);
        ans=min(ans, dp[door[1].first][door[1].second]);
    }
    cout<<ans<<"\n";
}