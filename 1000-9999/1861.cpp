#include <bits/stdc++.h>
using namespace std;

int n, board[102][102];
pair<int, int> dp[102][102];
int mv[5][2]={
    {0, 0},
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};
char direction[5]={'.', 'L', 'R', 'U', 'D'};
bool visited[101][101];

int solve(int y, int x){
    if(dp[y][x].second!=0) return dp[y][x].first;

    int ret=-987654321, dir;
    for(int i=1; i<=4; i++){
        int my=y+mv[i][0];
        int mx=x+mv[i][1];
        if(!visited[my][mx] && !(my==n-1 && mx==n-1) && 0<=my && my<n && 0<=mx && mx<n){
            visited[my][mx]=1;
            int res=solve(my, mx);
            if(res>ret){
                ret=res;
                dir=i;
            }
            visited[my][mx]=0;
        }
    }
    dp[y][x]=make_pair(ret+board[y][x], dir);
    return dp[y][x].first;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }
    dp[0][0]=make_pair(board[0][0], -1);

    visited[n-1][n-1]=1;
    cout<<solve(n-1, n-1)<<"\n";

    stack<char> s;
    pair<int, int> cur={n-1, n-1};
    
    while(!(cur.first==0 && cur.second==0)){
        pair<int, int> tmp=dp[cur.first][cur.second];
        s.push(direction[tmp.second]);
        cur.first=mv[tmp.second][0]+cur.first;
        cur.second=mv[tmp.second][1]+cur.second;
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    } cout<<"\n";
}