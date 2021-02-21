// 1753번 최단경로

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int V, E, K, u, v, w, dist[20001];
vector<pair<int, int>> graph[20001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>V>>E>>K;
    
    for(int i=1; i<=V; i++) dist[i]=INF;

    for(int i=0; i<E; i++){
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v, w));
    }
    
    dist[K]=0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, K));

    while(!q.empty()){
        int cur=q.top().second;
        int cos=-q.top().first;
        q.pop();

        if(cos>dist[cur]) continue;
        for(int i=0; i<graph[cur].size(); i++){
            int f=graph[cur][i].first;
            int nxt=graph[cur][i].second+cos;
            if(nxt<dist[f]){
                dist[f]=nxt;
                q.push(make_pair(-nxt, f));
            }
        }
    }

    for(int i=1; i<=V; i++){
        if(dist[i]==INF) cout<<"INF"<<"\n";
        else cout<<dist[i]<<"\n";
    }
}