#include <bits/stdc++.h>
using namespace std;

int n, m, k, y, x;
char a;
int board[1002][1002];
int mv[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};
bool visited[1002][1002][12];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a;
            board[i][j]=a-'0';
        }
    }

    queue<tuple<int, int, int>> q;
    int ans=1;
    q.push({1, 1, k});
    visited[1][1][k]=1;

    while(!q.empty()){
        int qs=q.size();
        for(int i=0; i<qs; i++){
            tie(y, x, k)=q.front(); q.pop();
            if(y==n && x==m){
                cout<<ans<<"\n";
                return 0;
            }
            for(int j=0; j<4; j++){
                int my=mv[j][0]+y;
                int mx=mv[j][1]+x;
                if(1<=my && my<=n && 1<=mx && mx<=m){
                    if(board[my][mx]==1 && k){
                        if(visited[my][mx][k-1]) continue;
                        visited[my][mx][k-1]=1;
                        q.push({my, mx, k-1});
                    } else if(board[my][mx]==0){
                        if(visited[my][mx][k]) continue;
                        visited[my][mx][k]=1;
                        q.push({my, mx, k});
                    }
                }
            }
        }
        ans++;
    }

    cout<<"-1"<<"\n";
}