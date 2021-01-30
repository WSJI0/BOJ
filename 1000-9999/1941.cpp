// 1941 소문난 칠공주

#include <bits/stdc++.h>
using namespace std;

int board[5][5], ans=0, check[5][5];
int mov[4][2]={
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
char a;

bool connected(int x){
    bool res=false;
    queue<pair<int, int>> q;
    q.push(make_pair(x/5, x%5));

    int c=0; bool visited[5][5]; memset(visited, 0, sizeof(visited));
    while(!q.empty()){
        pair<int, int> node=q.front(); q.pop();
        int ny=node.first, nx=node.second;
        if(visited[ny][nx]) continue;
        visited[ny][nx]=1;
        if(++c==7){
            res=true;
            break;
        }
        for(int i=0; i<4; i++){
            int mx=mov[i][0]+nx;
            int my=mov[i][1]+ny;
            if(mx>=0 && mx<5 && my>=0 && my<5){
                if(check[my][mx]) q.push(make_pair(my, mx));
            }
        }
    }
    return res;
}

void solve(int cnt, int cur, int x){
    if(cnt==7){
        if(cur>=4 && connected(x)) ans++;
        return;
    }
    if(cnt-cur>=4) return;
    for(int i=x+1; i<25; i++){
        check[i/5][i%5]=1;
        solve(cnt+1, cur+board[i/5][i%5], i);
        check[i/5][i%5]=0;
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>a;
            if(a=='S') board[i][j]=1;
            else board[i][j]=0;
        }
    }

    for(int i=0; i<25; i++){
        check[i/5][i%5]=1;
        solve(1, board[i/5][i%5], i);
        check[i/5][i%5]=0;
    }
    cout<<ans<<"\n";
}