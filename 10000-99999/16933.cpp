// 16933번 벽 부수고 이동하기 3

#include <bits/stdc++.h>
using namespace std;

int n, m, k, nx, ny, nk, nd, res, ans=-1, cnt=0;
char a;
int mov[4][2]={
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};
bool visited[1000][1000][11][2], board[1000][1000];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a;
            board[i][j]=a-'0';
        }
    }

    queue<tuple<int, int, int, int, int>> q;
    q.push(make_tuple(0, 0, k, 0, 0));
    visited[0][0][k][0]=1;

    while(!q.empty()){
        tie(nx, ny, nk, nd, res)=q.front(); q.pop();
        if(nx==m-1 && ny==n-1){
            ans=res;
            break;
        }
        for(auto v:mov){
            int mx=nx+v[0], my=ny+v[1];
            if(0<=mx && mx<m && 0<=my && my<n){
                if(board[my][mx]){
                    if(!nd && nk){
                        if(visited[mx][my][nk-1][(nd+1)%2]) continue;
                        q.push(make_tuple(mx, my, nk-1, (nd+1)%2, res+1));
                        visited[mx][my][nk-1][(nd+1)%2]=1;
                    } else{
                        if(visited[nx][ny][nk][(nd+1)%2]) continue;
                        q.push(make_tuple(nx, ny, nk, (nd+1)%2, res+1));
                        visited[nx][ny][nk][(nd+1)%2]=1;
                    }
                } else{
                    if(visited[mx][my][nk][(nd+1)%2]) continue;
                    q.push(make_tuple(mx, my, nk, (nd+1)%2, res+1));
                    visited[mx][my][nk][(nd+1)%2]=1;
                }
            }
        }
    }
    cout<<(ans>=0? ans+1:ans)<<"\n";
}