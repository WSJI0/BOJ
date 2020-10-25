#include <bits/stdc++.h>
using namespace std;

int parent[1000001];
int find(int u){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
}

void merge(int u, int v){
    u=find(u); v=find(v);
    if(u==v) return;
    if(u>v) parent[u]=v;
    else parent[v]=u;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b, o;
    
    cin>>n>>m;
    for(int i=0; i<=n; i++) parent[i]=i;
    while(m--){
        cin>>o>>a>>b;
        if(o==0)
            merge(a, b);
        else
            if(find(a)==find(b)) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
    }
}