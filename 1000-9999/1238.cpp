//1238번 파티

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m, x, a, b, t;
int cost[1001][1001], dp[1001];
vector<int> graph[1001];

void dijkstra(int s){
    for(int i=1; i<=n; i++) dp[i]=INF;
    dp[s]=0; priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int cur=pq.top().second;
        int cos=-pq.top().first;
        pq.pop();
        for(auto g:graph[cur]){
            if(dp[g]>cos+cost[cur][g]){
                pq.push(make_pair(-(cos+cost[cur][g]), g));
                dp[g]=cos+cost[cur][g];
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>x;
    for(int i=0; i<m; i++){
        cin>>a>>b>>t;
        cost[a][b]=t;
        graph[a].push_back(b);
    }
    int ans=0, res[1001];
    for(int i=1; i<=n; i++){
        dijkstra(i);
        res[i]=dp[x];
    }
    dijkstra(x);
    for(int i=1; i<=n; i++){
        ans=max(ans, res[i]+dp[i]);
    }
    cout<<ans<<"\n";
}