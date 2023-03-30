#include <bits/stdc++.h>
using namespace std;

int n, r, q, u, v;
vector<int> graph[100001];
int dp[100001];

int solve(int cur){
    if(dp[cur]) return dp[cur];
    dp[cur]=1;
    for(auto g:graph[cur]){
        if(dp[g]) continue;
        dp[cur]+=solve(g);
    }
    return dp[cur];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>r>>q;
    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    solve(r);

    for(int i=0; i<q; i++){
        cin>>u;
        cout<<dp[u]<<"\n";
    }
}