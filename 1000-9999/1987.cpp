// 1987번 알파벳

#include <bits/stdc++.h>
using namespace std;

int r, c, ans;
int mov[4][2]={
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
char board[21][21];
bool visited[27];

void solve(int y, int x, int cur){
    ans=max(ans, cur);
    for(auto v:mov){
        int mx=x+v[0];
        int my=y+v[1];
        if(0<=mx<c && 0<=my<r){
            if(visited[board[my][mx]-'A']) continue;
            visited[board[my][mx]-'A']=1;
            solve(my, mx, cur+1);
            visited[board[my][mx]-'A']=0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) cin>>board[i][j];
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            visited[board[i][j]-'A']=1;
            solve(i, j, 1);
            visited[board[i][j]-'A']=0;
        }
    }

    cout<<ans<<"\n";
}