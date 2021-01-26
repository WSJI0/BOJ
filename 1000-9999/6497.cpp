// 6497번 전력난

#include <bits/stdc++.h>
using namespace std;

pair<int, pair<int, int>> p(int x, int y, int z){
    return make_pair(x, make_pair(y, z));
}

int parent[200001];
int find(int u){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
}
void merge(int u, int v){
    u=find(u); v=find(v);
    if(u==v) return;
    if(u<v) parent[v]=u;
    else parent[u]=v;
}
bool check(int u, int v){
    if(find(u)==find(v)) return false;
    return true;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int m, n, x, y, z;
    while(1){
        cin>>m>>n;
        if(m==0 && n==0) break;
        for(int i=0; i<m; i++) parent[i]=i;

        vector<pair<int, pair<int, int>>> nodes;
        int ans=0;
        for(int i=0; i<n; i++){
            cin>>x>>y>>z;
            nodes.push_back(p(z, x, y));
            ans+=z;
        }
        sort(nodes.begin(), nodes.end());

        for(int i=0; i<n; i++){
            int cost=nodes[i].first, a=nodes[i].second.first, b=nodes[i].second.second;
            if(check(a, b)){
                ans-=cost;
                merge(a, b);
            }
        }
        cout<<ans<<"\n";
    }
}