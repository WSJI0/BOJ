//11657 타임머신

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m, a, b, c;
vector<pair<int, int>> graph[501];

vector<int> bellmanFord(int s){
    vector<int> dist(n);
    for(int i=0; i<n; i++) dist[i]=INF;
    dist[s]=0;

    for(int i=0; i<n-1; i++){
        for(int j=1; i<=n; j++){
            for(int k=0; k<graph[j].size(); k++){
                if(dist[j]==INF) continue;
                if(dist[graph[j][k].first]>graph[j][k].second+dist[j])
                    dist[graph[j][k].first]=graph[j][k].second+dist[j];
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<graph[i].size(); j++){
            if(dist[graph[i][j].first]==INF) continue;
            if(dist[graph[i][j].first]>graph[i][j].second+dist[i]){
                cout<<-1<<"\n";
                exit(0);
            }
        }
    } return dist;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b, c));
    }

    vector<int> dist=bellmanFord(1);
    for(int i=0; i<dist.size(); i++){
        cout<<dist[i]<<"\n";
    }
}