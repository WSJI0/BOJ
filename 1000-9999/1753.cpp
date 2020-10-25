#include <bits/stdc++.h>
using namespace std;
#define INF_NUM 9999999

int V, E, K, u, v, w;
vector<pair<int, int>> graph[20001];
vector<int> dijkstra(int);
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>V>>E>>K;
    for(int i=0; i<E; i++){
        cin>>u>>v>>w;
        graph[u].push_back(pair<int, int>(v, w));
    } 
    dijkstra(K);
}

vector<int> dijkstra(int s){
    vector<int> dist(V+1, INF_NUM);
    dist[s]=0;
    priority_queue<pair<int, int>> pq;
    pq.push(pair<int, int>(0, s));
    while(!pq.empty()){
        int cost=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(dist[cur]<cost) continue;
        for(int i=0; i<graph[cur].size(); i++){
            int f=graph[cur][i].first;
            int nxt=cost+graph[cur][i].second;
            if(dist[f]>nxt){
                dist[f]=nxt;
                pq.push(pair<int, int>(-nxt, f));
            }
        }
    }
    for(int i=1; i<=V; i++){
        if(dist[i]!=INF_NUM) cout<<dist[i]<<endl;
        else cout<<"INF"<<endl;
    }
}