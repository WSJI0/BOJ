#include <bits/stdc++.h>
using namespace std;

int n, m, r, plan[1001];
int parent[201], level[201]={1, };

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
        parent[u]=v;
        level[v]+=level[u];
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for(int i=0; i<=200; i++) parent[i]=i;

    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>r;
            if(r) merge(i, j);
        }
    }
    string ans="YES";
    for(int i=0; i<m; i++){
        cin>>plan[i];
        if(i>0){
            if(find(plan[i-1])!=find(plan[i])) ans="NO";
        }
    }
    cout<<ans<<"\n";
}