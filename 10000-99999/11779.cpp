//11779번 최소비용 구하기 2

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int cost[1001][1001];
pair<int, vector<int>> dp[1001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b, c, s, e;
    cin>>n>>m;

    for(int i=0; i<1001; i++){
        dp[i]=make_pair(INF, vector<int>());
        for(int j=0; j<1001; j++){
            cost[i][j]=INF;
        }
    }

    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        cost[a][b]=min(c, cost[a][b]);
    }
    cin>>s>>e;   
    dp[s]=make_pair(INF, vector<int>{s});
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));

    while(!pq.empty()){
        int cos=-pq.top().first;
        int cur=pq.top().second; 
        pq.pop();
        if(dp[cur].first<cos) continue;
        for(int i=1; i<=n; i++){
            if(cost[cur][i]!=INF){
                int nxt=cos+cost[cur][i];
                if(dp[i].first>nxt){
                    dp[i].first=nxt;
                    dp[i].second.clear();
                    for(auto j:dp[cur].second)
                        dp[i].second.push_back(j);
                    dp[i].second.push_back(i);
                    pq.push(make_pair(-nxt, i));
                }
            }
        }
    }

    cout<<dp[e].first<<"\n";
    cout<<dp[e].second.size()<<"\n";
    for(auto i:dp[e].second){
        cout<<i<<" ";
    } cout<<"\n";
}