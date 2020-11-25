#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int dist[101], cost[101][101], n, m, a, b, c;

int dijkstra(int s, int e){
    for(int i=1; i<=n; i++) 
    	dist[i]=INF;
    priority_queue<pair<int, int>> pq;
    dist[s]=0; 
    
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int cos=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(dist[cur]<cos) continue;
        for(int i=1; i<=n; i++){
            if(cost[cur][i]!=INF){
                int nxt=cos+cost[cur][i];
                if(dist[i]>nxt){
                    dist[i]=nxt;
                    pq.push(make_pair(-nxt, i));
                }
            }
        }
    }
    if(dist[e]==INF) 
    	cout<<"도달할 수 없음"<<"\n";
    return dist[e];
}

int main(void){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cost[i][j]=INF;
        }
    }

    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        cost[a][b]=c;
    }

    cout<<dijkstra(1, n)<<"\n";
}