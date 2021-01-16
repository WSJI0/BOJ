/*
MST - Prim (프림)
*/

#include <bits/stdc++.h>
using namespace std;

int v, e, a, b, c, visited[10001];
vector<pair<int, int>> graph[10001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>v>>e;

    for(int i=0; i<e; i++){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(-c, b));
        graph[b].push_back(make_pair(-c, a));    
    }

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 1));

    int ans=0;
    while(!pq.empty()){
        pair<int, int> p=pq.top(); pq.pop();
        if(visited[p.second]) continue;
        ans-=p.first;
        visited[p.second]=1;
        for(auto g:graph[p.second]){
            pq.push(g);
        }
    }

    cout<<ans<<"\n";
}