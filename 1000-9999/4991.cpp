#include <bits/stdc++.h>
using namespace std;

int w, h;
char board[21][21];
bool visited[21][21];
int mv[8][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

pair<int, int> robo;
vector<pair<int, int>> dirty;
int ans;

void solve(int cur, int bit){
    
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while(1){
        cin>>w>>h;
        if(w==0) break;

        ans=987654321;
        dirty.clear();
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>board[i][j];
                if(board[i][j]=='o'){
                    robo=make_pair(i, j);
                } else if(board[i][j]=='*'){
                    dirty.push_back(make_pair(i, j));
                }
            }
        }

        queue<pair<int, int>> q;
        q.push(robo);
        visited[robo.first][robo.second]=1;
        while(!q.empty()){
            pair<int, int> node=q.front(); q.pop();
            for(int i=0; i<8; i++){
                int my=node.first+mv[i][0];
                int mx=node.second+mv[i][1];
                if(0<=my && my<h && 0<=mx && mx<w){
                    if(visited[my][mx] || board[my][mx]=='x') continue;
                    visited[my][mx]=1;
                    q.push(make_pair(my, mx));
                }
            }
        }

        int ans=0;
        for(int i=0; i<dirty.size(); i++){
            if(!visited[dirty[i].first][dirty[i].second]){
                ans=-1;
                break;
            }
        }
        if(ans==-1){
            cout<<ans<<"\n";
            continue;
        }

        for(int i=0; i<dirty.size(); i++){
            solve(i, bit);
        }
    }
}