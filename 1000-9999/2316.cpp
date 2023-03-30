#include <bits/stdc++.h>
using namespace std;

int n, p, u, v;
int cap[401][401], flow[401][401];
vector<int> graph[401];
int parent[401];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>p;
    for(int i=0; i<p; i++){
        cin>>u>>v;
        cap[u][v]=1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int ans=0;
    while(1){
        memset(parent, 0, sizeof(parent));
        queue<int> q;
        q.push(1);
        parent[1]=-1;

        while(!q.empty() && !parent[2]){
            int cur=q.front(); q.pop();
            for(auto nxt:graph[cur]){
                if(cap[cur][nxt]-flow[cur][nxt]>0 && !parent[nxt]){
                    q.push(nxt);
                    parent[nxt]=cur;
                    if(nxt==2) break;
                }
            }
        }
        if(!parent[2]) break;

        int cur=2;
        while(parent[cur]!=-1){
            flow[parent[cur]][cur]=1;
            flow[cur][parent[cur]]=-1;
            cur=parent[cur];
        }
        ans++;
    }
    cout<<ans<<"\n";
}