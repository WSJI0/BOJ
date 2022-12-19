// 16236번 아기 상어

#include <bits/stdc++.h>
using namespace std;

int n, board[21][21], sy, sx, ans, siz=2, need=2;
int mv[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};
bool visited[21][21];

int getDistance(int y, int x){
    queue<pair<int, int>> q;
    int res=0;
    
    q.push(make_pair(sy, sx));
    memset(visited, 0, sizeof(visited));
    visited[sy][sx]=1;
    while(!q.empty()){
        int qs=q.size();
        res++;
        for(int i=0; i<qs; i++){
            int cy=q.front().first;
            int cx=q.front().second;
            q.pop();
            for(int j=0; j<4; j++){
                int ny=cy+mv[j][0];
                int nx=cx+mv[j][1];
                if(0<=ny && ny<n && 0<=nx && nx<n){
                    if(!visited[ny][nx] && board[ny][nx]<=siz){
                        if(ny==y && nx==x) return res;
                        q.push(make_pair(ny, nx));
                        visited[ny][nx]=1;
                    }
                }
            }
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            if(board[i][j]==9){
                sy=i;
                sx=j;
                board[i][j]=0;
            }
        }
    }
    while(1){
        int ny=-1, nx=-1, cur=9999;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==0) continue;
                int d=getDistance(i, j);
                if(board[i][j]<siz && d!=-1){
                    if(cur>d){
                        cur=d;
                        ny=i; nx=j;
                    }
                }
            }
        }
        if(ny==-1) break;

        ans+=getDistance(ny, nx);
        int d=getDistance(ny, nx);
        sy=ny; sx=nx; need--;
        board[ny][nx]=0;
        if(need==0) need=++siz;
    }
    cout<<ans<<"\n";
}