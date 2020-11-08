//19238번 스타트 택시
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, f, sx, sy;
    cin>>n>>m>>f;
    int board[20][20];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }
    cin>>sx>>sy;
    vector<pair<pair<int, int>, pair<int, int>>> coor(m);
    for(int i=0; i<m; i++)
        cin>>coor[i].first.first>>coor[i].first.second>>coor[i].second.first>>coor[i].second.second;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    int move[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    unordered_map<pair<int, int>, bool> visited;
    while(!q.empty()){
        pair<int, int> node=q.front(); q.pop();
        visited[node]=true;
        for(auto v:move){
            int mx=node.first+v[0];
            int my=node.second+v[1];
            if(0<=mx && mx<n && 0<=my && my<n){
                if(visited[make_pair(mx, my)]==0){
                    
                }
            }
        }
    }

}