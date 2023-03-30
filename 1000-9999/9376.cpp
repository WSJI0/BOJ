#include <bits/stdc++.h>
using namespace std;

int t, h, w, ey, ex, cv;
char board[105][105];
int vis1[105][105], vis2[105][105], vis3[105][105], res[105][105];
int mv[4][2]={
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};
int prisoner[2][2];

void solve(int sy, int sx, int (*vis)[105]){
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    vis[sy][sx]=0;
    while(!q.empty()){
        tie(ey, ex)=q.front(); q.pop();
        for(int i=0; i<4; i++){
            int my=ey+mv[i][0];
            int mx=ex+mv[i][1];
            if(0<=my && my<=h+1 && 0<=mx && mx<=w+1){
                if(board[my][mx]=='*') continue;
                if(board[my][mx]=='.' || board[my][mx]=='$'){
                    if(vis[my][mx]<=vis[ey][ex]) continue;
                    vis[my][mx]=vis[ey][ex];
                } else if(board[my][mx]=='#'){
                    if(vis[my][mx]<=vis[ey][ex]+1) continue;
                    vis[my][mx]=vis[ey][ex]+1;
                }
                q.push(make_pair(my, mx));
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        for(int i=0; i<105; i++){
            for(int j=0; j<105; j++){
                vis1[i][j]=vis2[i][j]=vis3[i][j]=999999;
                board[i][j]='.';
            }
        }
        prisoner[0][0]=-1;

        cin>>h>>w;
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                cin>>board[i][j];
                if(board[i][j]=='$'){
                    if(prisoner[0][0]==-1){
                        prisoner[0][0]=i; prisoner[0][1]=j;
                    } prisoner[1][0]=i; prisoner[1][1]=j;
                }
            }
        }

        solve(0, 0, vis1);
        solve(prisoner[0][0], prisoner[0][1], vis2);
        solve(prisoner[1][0], prisoner[1][1], vis3);
        
        int ans=987654321;
        for(int i=0; i<=h; i++){
            for(int j=0; j<=w; j++){
                res[i][j]=vis1[i][j]+vis2[i][j]+vis3[i][j];
                if(board[i][j]=='#') ans=min(ans, res[i][j]-2);
                if(i==1 || i==h || j==1 || j==w){
                    if(board[i][j]=='.') ans=min(ans, res[i][j]);
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}