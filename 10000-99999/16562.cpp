#include <bits/stdc++.h>
using namespace std;

int parent[10001];
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
    int n, m, k, v, w;
    cin>>n>>m>>k;
    vector<int> a(n);
    vector<int> pay(n+1, 99999);
    for(int i=0; i<n; i++){
        cin>>a[i];
        parent[i]=i;
    }
    for(int i=0; i<m; i++){
        cin>>v>>w;
        merge(v, w);
    }
    for(int i=1; i<=n; i++) 
        pay[find(i)]=min(pay[find(i)], a[i-1]);

    int ans=0;
    for(int i=0; i<n; i++)
        if(pay[i]!=99999) ans+=pay[i];
    
    if(ans<=k) cout<<ans<<"\n";
    else cout<<"Oh no"<<"\n";
}