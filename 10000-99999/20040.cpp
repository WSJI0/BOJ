//20040 사이클 게임

#include <bits/stdc++.h>
using namespace std;

int parent[500001]={-1,};
int find(int u){
    if(parent[u]==u) return u;
    return parent[u]=find(parent[u]);
}

bool merge(int u, int v){
    u=find(u); v=find(v);
    if(u==v) return false;
    if(u>v) parent[u]=v;
    else parent[v]=u;
    return true;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b, ans=0;
    cin>>n>>m;
    for(int i=0; i<n; i++) parent[i]=i;
    for(int i=1; i<=m; i++){
        cin>>a>>b;
        if(!merge(a, b)){
            ans=i;
            break;
        }
    }
    cout<<ans<<"\n";
}