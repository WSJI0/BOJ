#include <bits/stdc++.h>
using namespace std;

int n, u, v, m, c, root, ac[40001][20], depth[40001];
vector<pair<int, int>> graph[40001];

void getTree(int cur, int parent){
    depth[cur]=depth[parent]+1;
    ac[cur][0]=parent;

    for(int i=1; i<=20; i++){
        ac[cur][i]=ac[ac[cur][i-1]][i-1];
    }
    for(int i=0; i<graph[cur].size(); i++){
        int nxt=graph[cur][i].first;
        if(nxt==parent) continue;
        getTree(nxt, cur);
    }   
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>u>>v>>c;
        graph[u].push_back(make_pair(v, c));
        if(i==0 || root==v) root=u;
    }

    depth[0]=-1;
    getTree(1, 0);

    cin>>m;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        if(depth[u]!=depth[v]){
            if(depth[u]>depth[v]) swap(u, v);
            for(int j=20; j>=0; j--){
                if(depth[u]<=depth[ac[v][j]]) v=ac[v][j];
            }
        }
        int ans=u;
        if(u!=v){
            for(int j=20; j>=0; j--){
                if(ac[u][j]!=ac[v][j]){
                    u=ac[u][j];
                    v=ac[v][j];
                }
                ans=ac[u][j];
            }
        }
        cout<<ans<<"\n";
    }
}