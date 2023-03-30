#include <bits/stdc++.h>
using namespace std;

int t, n, m, u, v, id;
int dp[100001];
bool no[100001];
vector<int> graph[100001];

void solve(int cur, int start){
    for(auto g:graph[cur]){
        if(dp[g]==0){
            dp[g]=dp[start];
            solve(g, start);
        } else if(g!=start){
            no[dp[start]]=1;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        for(int i=0; i<=100000; i++){
            graph[i].clear();
            no[i]=dp[i]=0;
        } id=0;

        cin>>n>>m;
        for(int i=0; i<m; i++){
            cin>>u>>v;
            graph[u].push_back(v);
        }

        for(int i=1; i<=n; i++){
            if(!dp[i]){
                dp[i]=++id;
                solve(i, i);
            }
        }

        int ans=0;
        for(int i=1; i<id; i++){
            if(!no[i]) ans++;
        }
        cout<<ans<<"\n";
    }
}