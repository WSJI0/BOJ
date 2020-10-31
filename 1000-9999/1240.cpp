//1240 노드 사이의 거리

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> graph;
int cost[1001][1001];

int bfs(int a, int b){
    queue<pair<int, int>> q; q.push(pair<int, int>(a, 0));
    unordered_map<int, bool> visited;
    visited[q.front().first]=1;
    while(!q.empty()){
        pair<int, int> node=q.front(); q.pop();
        for(int i=0; i<graph[node.first].size(); i++){
            if(graph[node.first][i]==b){
                return node.second+cost[node.first][graph[node.first][i]];
            }
            else if(!visited[graph[node.first][i]]){
                q.push(pair<int, int>(graph[node.first][i], node.second+cost[node.first][graph[node.first][i]]));
                visited[node.first]=1;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b, c;
    cin>>n>>m;
    for(int i=0; i<n-1; i++){
        cin>>a>>b>>c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cost[a][b]=c;
        cost[b][a]=c;
    }
    while(m--){
        int i, j;
        cin>>i>>j;
        cout<<bfs(i, j)<<"\n";
    }
}