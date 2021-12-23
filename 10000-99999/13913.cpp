/*
13913번
숨바꼭질 4
*/

#include <bits/stdc++.h>
using namespace std;

char board[13][7];
bool visited[13][7];
queue<pair<int, int>> q;
queue<pair<int, int>> py;
int ans, mv[4][2]={
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

void fall(){
    queue<char> q;
    for(int i=0; i<6; i++){
        for(int j=11; j>=0; j--){
            if(board[j][i]!='.') q.push(board[j][i]);
            board[j][i]='.';
        }
        int qs=q.size();
        for(int j=0; j<qs; j++){
            board[11-j][i]=q.front();
            q.pop();
        }
    }
}

void puyoPop(queue<pair<int, int>>& q){
    while(!q.empty()){
        pair<int, int> node=q.front(); q.pop();
        board[node.first][node.second]='.';
    }
}

bool puyo(){
    bool p=false; char cur; 
    for(int y=0; y<12; y++){
        for(int x=0; x<6; x++){
            if(board[y][x]=='.' || visited[y][x]) continue;
            q.push(make_pair(y, x)); cur=board[y][x];
            py.push(make_pair(y, x)); visited[y][x]=1;
            while(!q.empty()){
                pair<int, int> node=q.front(); q.pop();
                for(int i=0; i<4; i++){
                    int my=node.first+mv[i][0], mx=node.second+mv[i][1];
                    if(0<=my && my<12 && 0<=mx && mx<6 && !visited[my][mx]){
                        if(board[my][mx]==cur){
                            visited[my][mx]=1;
                            q.push(make_pair(my, mx));
                            py.push(make_pair(my, mx));
                        }
                    }
                }
            }
            if(py.size()>=4){
                puyoPop(py);
                p=true;
            } else{
                while(!py.empty()) py.pop();
            }
        }
    }
    
    fall();
    if(p) ans++;

    return p;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++) cin>>board[i][j];
    }

    while(puyo()) memset(visited, 0, sizeof(visited));

    cout<<ans<<"\n";
}
