#include <bits/stdc++.h>
using namespace std;

int n, m, board[501][501], ans;
int mv[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void solve(int y, int x, int cur, int d, int s){
    if(cur==3){
        ans=max(ans, s);
        return;
    }
    for(int i=0; i<4; i++){
        if(i==d) continue;
        int my=mv[i][0]+y;
        int mx=mv[i][1]+x;
        if(0<=my && my<n && 0<=mx && mx<m){
            solve(my, mx, cur+1, i+(i%2? -1:1), s+board[my][mx]);
        }
    }
}

void solve2(int y, int x){
    for(int i=0; i<4; i++){
        int res=board[y][x];
        for(int j=0; j<4; j++){
            if(i==j) continue;
            int my=mv[j][0]+y;
            int mx=mv[j][1]+x;
            if(0<=my && my<n && 0<=mx && mx<m){
                res+=board[my][mx];
            } else break;
        }
        ans=max(ans, res);
    } 
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>board[i][j];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            solve(i, j, 0, -1, board[i][j]);
            solve2(i, j);
        }
    }
    cout<<ans<<"\n";
}