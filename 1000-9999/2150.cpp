//2150번 Strongly Connected Component

#include <bits/stdc++.h>
using namespace std;

int v, e, a, b, vis[10001], id=0;
bool fin[10001];
vector<int> graph[10001];
vector<vector<int>> scc;
stack<int> s;

int dfs(int x){
    vis[x]=++id;
    s.push(x);
    int parent=vis[x];
    for(auto y:graph[x]){
        if(vis[y]==0) parent=min(parent, dfs(y));
        else if(!fin[y]) parent=min(parent, vis[y]);
    }
    if(parent==vis[x]){
        vector<int> sc;
        while(1){
            int t=s.top(); s.pop();
            sc.push_back(t);
            fin[t]=1;
            if(t==x) break;
        }
        scc.push_back(sc);
    }
    return parent;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>v>>e;
    for(int i=0; i<e; i++){
        cin>>a>>b;
        graph[a].push_back(b);
    }
    for(int i=1; i<=v; i++) 
        if(vis[i]==0) dfs(i);
    
    cout<<scc.size()<<"\n";
    for(int i=0; i<scc.size(); i++)
        sort(scc[i].begin(), scc[i].end());
    sort(scc.begin(), scc.end());
    for(int i=0; i<scc.size(); i++){
        for(int j=0; j<scc[i].size(); j++)
            cout<<scc[i][j]<<" ";
        cout<<"-1"<<"\n";
    }
}