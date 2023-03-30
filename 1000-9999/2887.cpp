//2887번 행성 터널

#include <bits/stdc++.h>
using namespace std;

struct coor{
    int x, y, z;
};

int n, x, y, z;
int parent[100001], level[100001]={1, };
vector<tuple<int, int, int>> path;
vector<pair<int, int>> X, Y, Z;

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
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<=100000; i++) parent[i]=i;

    cin>>n;
    vector<coor> planet(n);
    for(int i=0; i<n; i++){
        cin>>planet[i].x>>planet[i].y>>planet[i].z;
        X.push_back({planet[i].x, i});
        Y.push_back({planet[i].y, i});
        Z.push_back({planet[i].z, i});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    for(int i=0; i<n-1; i++){
        path.push_back({X[i+1].first-X[i].first, X[i].second, X[i+1].second});
        path.push_back({Y[i+1].first-Y[i].first, Y[i].second, Y[i+1].second});
        path.push_back({Z[i+1].first-Z[i].first, Z[i].second, Z[i+1].second});
    }
    sort(path.begin(), path.end());

    int ans=0;
    for(int i=0; i<path.size(); i++){
        int dis, s, e;
        tie(dis, s, e)=path[i];
        if(find(s)==find(e)) continue;
        ans+=dis;
        merge(s, e);
    }

    cout<<ans<<"\n";
}