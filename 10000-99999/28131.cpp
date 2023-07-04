#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m, k, s, t, u, v, w;
vector<pair<int, int>> graph[10001];
int dp[10001][51];

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m>>k>>s>>t;
    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
    }

    for(int i=0; i<=10000; i++){
        for(int j=0; j<=50; j++) dp[i][j]=INF;
    }

    queue<pair<int, int>> q;
    q.push({s, 0}); dp[s][0]=0;
    while(!q.empty()){
        pair<int, int> node=q.front(); q.pop();
        // if(node.first==t) continue;
        for(auto g:graph[node.first]){
            int nxt=g.first, cost=dp[node.first][node.second]+g.second;
            if(cost<dp[nxt][cost%k]){
                dp[nxt][cost%k]=cost;
                q.push({nxt, cost%k});
            }
        }
    }

    if(dp[t][0]==INF) cout<<"IMPOSSIBLE"<<"\n";
    else cout<<dp[t][0]<<"\n";
}