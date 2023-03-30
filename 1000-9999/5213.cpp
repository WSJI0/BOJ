#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> tile[501][501];
bool visited[501][501];
int ans[501], r_ans[501], rl;
int mv[4][2]={
    {1, -1}, {1, 0}, {0, -1}, {0, 1}
};
int maxTile=0;

void solve(int y, int x, int cur){
    for(int i=0; i<4; i++){
        int my=y+mv[i][0];
        int mx=x+mv[i][1];
        if(0<=my && my<n && 0<=mx && mx<n){
            if(visited[my][mx]) continue;
            if((i==0 || i==2) && tile[y][x].first!=tile[my][mx].second) continue;
            if((i==1 || i==3) && tile[y][x].second!=tile[my][mx].first) continue;
            visited[my][mx]=1;
            ans[cur]=(my*n+mx+1);
            if(maxTile<my*n+mx+1){
                for(int i=0; i<cur; i++) r_ans[i]=ans[i];
                rl=cur;
                maxTile=my*n+mx+1;
            }
            solve(my, mx, cur+1);
        }
    } 
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-(i%2); j++) cin>>tile[i][j].first>>tile[i][j].second;
    }

    queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        visited[0][i]=1; ans[0]=i+1;
        if(maxTile<i+1){
            for(int i=0; i<1; i++) r_ans[i]=ans[i];
            rl=1;
            maxTile=i+1;
        }
        solve(0, i, 1);
        visited[0][i]=0;
    }

    cout<<rl<<"\n";
    for(int i=0; i<rl; i++){
        cout<<r_ans[i]<<" ";
    } cout<<"\n";
}