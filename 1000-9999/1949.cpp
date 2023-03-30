#include <bits/stdc++.h>
using namespace std;

int n, u, v, w[10002];
vector<int> graph[10002];
int dp[10002][2];

int solve(int cur, int sel, int pre){
    if(dp[cur][sel]) return dp[cur][sel];
    if(sel) dp[cur][sel]=w[cur];

    for(auto g:graph[cur]){
        if(g==pre) continue;
        if(!sel){
            dp[cur][sel]+=max(solve(g, 1, cur), solve(g, 0, cur));
        } else{
            dp[cur][sel]+=solve(g, 0, cur);
        }
    }
    return dp[cur][sel];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++) cin>>w[i];
    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout<<max(solve(1, 1, 0), solve(1, 0, 0))<<"\n";
}