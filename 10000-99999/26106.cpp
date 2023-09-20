#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int m, n, k, v, w, x, y, c, z; 
vector<pair<int, int>> graph[30001];
unordered_map <string, bool> ft;
unordered_map <string, int> dist;

string cv(int x, int y, int z=-1){
    return to_string(x)+"."+to_string(y)+"."+to_string(z);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>m>>n>>k>>v>>w;
    for(int i=0; i<m; i++){
        cin>>x>>y>>c;
        graph[x].push_back({y, c});
    }

    for(int i=0; i<n; i++){
        if(i==v) continue;
        for(int j=0; j<n; j++){
            dist[cv(i, j)]=INF;
        }
    }

    for(int i=0; i<k; i++){
        cin>>x>>y>>z;
        ft[cv(x, y, z)]=1;
    }

    
    priority_queue<tuple<int, int, int>> pq; // cost cur prev
    pq.push({0, v, -1});

    int cost, cur, prev;
    while(!pq.empty()){
        tie(cost, cur, prev)=pq.top(); pq.pop();
        cost*=-1;
        for(auto g:graph[cur]){
            if(cost+g.second>=dist[cv(g.first, cur)] || ft[cv(prev, cur, g.first)]) continue;
            dist[cv(g.first, cur)]=cost+g.second;
            pq.push({-(cost+g.second), g.first, cur});
        }
    }

    int ans=INF;
    for(int i=0; i<n; i++){
        ans=min(ans, dist[cv(w, i)]);
    }

    cout<<(ans==INF? -1:ans)<<"\n";
}

