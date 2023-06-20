#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[1001][1001];
int mv[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin>>board[i][j];
    }

    int ans=0;
    queue<pair<int, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]) continue;
            q.push({i, j}); board[i][j]=1;
            ans++;
            while(!q.empty()){
                pair<int, int> node=q.front(); q.pop();
                int y=node.first; int x=node.second;
                for(auto v:mv){
                    int my=(y+v[0]+n)%n; int mx=(x+v[1]+m)%m;
                    if(board[my][mx]) continue;
                    board[my][mx]=1;
                    q.push({my, mx});
                }
            }
        }
    }

    cout<<ans<<"\n";
}