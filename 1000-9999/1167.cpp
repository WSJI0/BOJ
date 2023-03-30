#include <bits/stdc++.h>
using namespace std;
#define INF 1234567890

int v, n, e, c;
vector<pair<int, int>> tree[100001];
int dist[1000001];

void dijkstra(int s){
    dist[s]=0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));

    while(!pq.empty()){
        pair<int, int> node=pq.top(); pq.pop();
        int cur=node.second; int cost=-node.first;
        for(auto i:tree[cur]){
            int nxt=i.first;
            int nc=i.second;
            if(dist[nxt]<=cost+nc) continue;
            dist[nxt]=cost+nc;
            pq.push(make_pair(-(cost+nc), nxt));
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>v;
    for(int i=0; i<v; i++){
        cin>>n;
        while(1){
            cin>>e;
            if(e==-1) break;
            cin>>c;
            tree[n].push_back(make_pair(e, c));
        }
    }

    for(int i=1; i<=v; i++) dist[i]=INF;
    dijkstra(1);
    int mv=0, idx=0;
    for(int i=1; i<=v; i++){
        if(dist[i]>mv){
            mv=dist[i];
            idx=i;
        }
        dist[i]=INF;
    }
    dijkstra(idx);
    mv=0;
    for(int i=1; i<=v; i++){
        mv=max(mv, dist[i]);
    }
    cout<<mv<<"\n";
}