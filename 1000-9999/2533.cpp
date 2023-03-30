// 2533번 사회망 서비스(SNS)

#include <bits/stdc++.h>
using namespace std;

int n, u, v;
vector<int> graph[1000002];
int dp[1000002][2];

int solve(int cur, int sel, int pre){
    if(dp[cur][sel]) return dp[cur][sel];
    if(sel) dp[cur][sel]=1;
    for(auto g:graph[cur]){
        if(g==pre) continue;
        if(!sel){
            dp[cur][sel]+=solve(g, 1, cur);
        } else{
            int v1=solve(g, 0, cur);
            int v2=solve(g, 1, cur);
            dp[cur][sel]+=min(v1, v2);
        }
    }
    return dp[cur][sel];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout<<min(solve(1, 1, 0), solve(1, 0, 0))<<"\n";
}