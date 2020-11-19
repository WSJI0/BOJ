//1504번 특정한 최단 경로

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int cost[801][801];
int dp[801];
int n, e, a, b, c, v1, v2;
bool res=true;

int dijkstra(int s, int e){
    for(int i=1; i<=n; i++) dp[i]=INF;
    priority_queue<pair<int, int>> pq;
    dp[s]=0; pq.push(make_pair(0, s));
    while(!pq.empty()){
        int cos=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(dp[cur]<cos) continue;
        for(int i=1; i<=n; i++){
            if(cost[cur][i]!=INF){
                int nxt=cos+cost[cur][i];
                if(dp[i]>nxt){
                    dp[i]=nxt;
                    pq.push(make_pair(-nxt, i));
                }
            }
        }
    }
    if(dp[e]==INF) res=false;
    return dp[e];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>e;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cost[i][j]=INF;
    }
    for(int i=0; i<e; i++){
        cin>>a>>b>>c;
        cost[a][b]=cost[b][a]=min(cost[a][b], c);
    }
    cin>>v1>>v2;

    int ans1=dijkstra(1, v1)+dijkstra(v1, v2)+dijkstra(v2, n);
    if(!res) ans1=987654321;
    int ans2=dijkstra(1, v2)+dijkstra(v2, v1)+dijkstra(v1, n);
    if(!res) ans2=-1;
    cout<<min(ans1, ans2)<<"\n";
}