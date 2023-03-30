#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, q, x, y;
vector<pair<int, int>> graph[100001];
int parent[100001], level[100001]={1, };

int find(int u){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
}

void merge(int u, int v){
    u=find(u); v=find(v);
    if(u==v) return;
    if(level[u]>level[v]){
        parent[v]=u;
        level[u]+=level[v];
    } else{
        parent[v]=u;
        level[v]+=level[u];
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        graph[a].push_back({b, c});
    }
    
    cin>>q;
    for(int i=0; i<q; i++){
        cin>>x>>y;
        
    }
}