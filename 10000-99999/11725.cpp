#include <bits/stdc++.h>
using namespace std;

int n, u, v;
vector<int> graph[100001];
int parent[100001];

void dfs(int cur, int pre){
    for(auto g:graph[cur]){
        if(g==pre) continue;
        parent[g]=cur;
        dfs(g, cur);
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);
    for(int i=2; i<=n; i++) cout<<parent[i]<<"\n";
}