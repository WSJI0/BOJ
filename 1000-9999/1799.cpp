// 1799번 비숍

#include <bits/stdc++.h>
using namespace std;

int n, board[11][11], color[11][11], ans[2];
bool visited[11][11];

bool check(int cur){
    int my=cur/n;
    int mx=cur%n;
    while(1){
        if(--my<0 || ++mx>=n) break;
        
        if(visited[my][mx]) return false;
    }
    my=cur/n;
    mx=cur%n;
    while(1){
        if(--my<0 || --mx<0) break;
        if(visited[my][mx]) return false;
    }
    return true;
}

void solve(int cur, int res, int c){
    ans[c]=max(ans[c], res);
    for(int i=cur; i<n*n; i++){
        if(color[i/n][i%n]!=c) continue;
        if(board[i/n][i%n] && check(i)){
            visited[i/n][i%n]=1;
            solve(i+1, res+1, c);
            visited[i/n][i%n]=0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            color[i][j]=(i%2==j%2);
        }
    }

    solve(0, 0, 0);
    solve(0, 0, 1);

    cout<<ans[0]+ans[1]<<"\n";
}