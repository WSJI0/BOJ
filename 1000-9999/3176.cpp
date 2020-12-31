// 3176 도로 네트워크 (미완성)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int depth[100001], ac[100001][21];
vector<int> graph[100001];

void getTree(int cur, int parent){
    depth[cur]=depth[parent]+1;
    ac[cur][0]=parent;

    for(int i=1; i<=20; i++){
        ac[cur][i]=ac[ac[cur][i-1]][i-1];
    }
    for(int i=0; i<graph[cur].size(); i++){
        int nxt=graph[cur][i];
        if(nxt==parent) continue;
        getTree(nxt, cur);
    }   
}

map<pair<int, int>, int> cost;
ll dfs(int cur, int des){
    cout<<"CUR: "<<cur<<"\n";
    if(cur==des) return cost[make_pair(cur, des)];
    for(auto g:graph[cur]){
        if(depth[cur]>depth[des])
            if(depth[g]>=depth[cur]) continue;
        if(depth[cur]<depth[des])
            if(depth[g]<=depth[cur]) continue;
        return dfs(g, des)+cost[make_pair(cur, g)];
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, a, b, c;
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>a>>b>>c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cost[make_pair(a, b)]=c;
        cost[make_pair(b, a)]=c;
    }
    depth[0]=-1;
    getTree(1, 0);

    cin>>k;
    for(int i=0; i<k; i++){
        cin>>a>>b;
        if(depth[a]!=depth[b]){
            if(depth[a]>depth[b]) swap(a, b);
            for(int j=20; j>=0; j--){
                if(depth[a]<=depth[ac[b][j]]) b=ac[b][j];
            }
        }
        int lca=a;
        if(a!=b){
            for(int j=20; j>=0; j--){
                if(ac[a][j]!=ac[b][j]){
                    a=ac[a][j];
                    b=ac[b][j];
                }
                lca=ac[a][j];
            }
        }
        int ans=dfs(a, lca)+dfs(b, lca);
        cout<<ans<<"\n";
    }
}
