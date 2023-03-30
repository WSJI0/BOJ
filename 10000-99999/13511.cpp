#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n, u, v, m, q, k, w;
int level[100001], ac[100001][20];
vector<pair<int, int>> graph[100001];
ll cost[100001];

int lca(int a, int b){
    if(level[a]!=level[b]){
        if(level[a]>level[b]) swap(a, b);
        for(int i=19; i>=0; i--){
            if(level[a]<=level[ac[b][i]]) b=ac[b][i];
        }
    }
    int res=a;
    if(a!=b){
        for(int i=19; i>=0; i--){
            if(ac[a][i]!=ac[b][i]){
                a=ac[a][i];
                b=ac[b][i];
            } res=ac[a][i];
        }
    }
    return res;
}

int solve(int a, int b, int k, int l){
    if(level[a]!=level[l]){
        for(int i=19; i>=0; i--){
            if(level[l]<=level[ac[a][i]]){
                if((1<<i)>k) continue;
                a=ac[a][i];
                k-=(1<<i);
            }
        }
    }
    if(k==0) return a;
    int lb=(level[l]+k);
    if(level[b]!=lb){
        for(int i=19; i>=0; i--){
            if(lb<=level[ac[b][i]]){
                b=ac[b][i];
            }
        }
    }
    return b;
}

void get_table(int cur, int parent){
    level[cur]=level[parent]+1;
    ac[cur][0]=parent;

    for(int i=1; i<=19; i++){
        ac[cur][i]=ac[ac[cur][i-1]][i-1];
    }
    for(auto g:graph[cur]){
        if(g.first==parent) continue;
        get_table(g.first, cur);
    }
}

void get_cost(int cur, int parent, int cs){
    cost[cur]=cost[parent]+cs;
    for(auto g:graph[cur]){
        if(g.first==parent) continue;
        get_cost(g.first, cur, g.second);
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    level[0]=-1;
    get_table(1, 0);
    get_cost(1, 0, 0);

    cin>>m;
    while(m--){
        cin>>q>>u>>v;
        if(q==2) cin>>k;

        if(q==1){
            int l=lca(u, v);
            cout<<(cost[u]-cost[l])+(cost[v]-cost[l])<<"\n";
        } else{
            cout<<solve(u, v, k-1, lca(u, v))<<"\n";
        }
    }
}