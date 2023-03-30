#include <bits/stdc++.h>
using namespace std;

int w, h;
char board[101][101];
int laser[2][2];
int visited[101][101];
int mv[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void solve(int cy, int cx, int dir, int cur);

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    laser[0][0]=-1;

    cin>>w>>h;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>board[i][j];
            if(board[i][j]=='C'){
                if(laser[0][0]==-1){
                    laser[0][0]=i; laser[0][1]=j;
                } laser[1][0]=i; laser[1][1]=j;
            }
        }
    }

    int ans=999999;
    for(int i=0; i<4; i++){
        for(int j=0; j<h; j++){
            for(int k=0; k<w; k++) visited[j][k]=999999;
        }
        visited[laser[0][0]][laser[0][1]]=0;
        solve(laser[0][0], laser[0][1], i, 0);
        ans=min(ans, visited[laser[1][0]][laser[1][1]]);
    }

    cout<<ans<<"\n";
}

void solve(int cy, int cx, int dir, int cur){
    for(int i=0; i<4; i++){
        int my=cy+mv[i][0];
        int mx=cx+mv[i][1];
        if(0<=my && my<h && 0<=mx && mx<w){
            if(board[my][mx]=='*') continue;
            if(i==dir){
                if(visited[my][mx]<=cur) continue;
                visited[my][mx]=cur;
                solve(my, mx, dir, cur);
            } else{
                if(visited[my][mx]<=cur+1) continue;
                visited[my][mx]=cur+1;
                solve(my, mx, i, cur+1);
            }
        }
    }
}