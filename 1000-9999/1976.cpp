//1976번 여행 가자

#include <bits/stdc++.h>
using namespace std;

int parent[201];
int find(int u){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
}

void merge(int u, int v){
    u=find(u); v=find(v);
    if(u==v) return;
    parent[u]=v;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, a, f;
    cin>>n>>m;
    for(int i=1; i<=n; i++) parent[i]=i;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a;
            if(a==1) merge(i, j);
        }
    }
    cin>>f;
    f=find(f);
    bool ans=true;
    for(int i=1; i<m; i++){
        cin>>a;
        if(find(a)!=f) ans=false;
    }

    cout<<(ans? "YES":"NO")<<"\n";
}