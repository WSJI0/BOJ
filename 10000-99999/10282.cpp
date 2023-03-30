#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int t, n, d, c, a, b, s;
int dist[10001];
vector<pair<int, int>> graph[10001];

void dijkstra(int s){
    dist[s]=0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));

    while(!pq.empty()){
        int cur=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        for(int i=0; i<graph[cur].size(); i++){
            int nxt=graph[cur][i].first;
            int nc=cost+graph[cur][i].second;
            if(dist[nxt]<=nc) continue;
            dist[nxt]=nc;
            pq.push(make_pair(-nc, nxt));
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        for(int i=0; i<=10000; i++){
            while(!graph[i].empty()) graph[i].pop_back();
        }

        cin>>n>>d>>c;
        for(int i=0; i<d; i++){
            cin>>a>>b>>s;
            graph[b].push_back(make_pair(a, s));
        }

        for(int i=0; i<=10000; i++) dist[i]=INF;
        dijkstra(c);

        int cnt=0, ans=0;
        for(int i=1; i<=n; i++){
            if(dist[i]==INF) continue;
            cnt++;
            ans=max(ans, dist[i]);
        }

        cout<<cnt<<" "<<ans<<"\n";
    }
}