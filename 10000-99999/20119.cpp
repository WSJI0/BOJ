// 20119번 클레어와 물약

#include <bits/stdc++.h>
using namespace std;

int n, m, k, x[200001], y, r, l, indgree[200001];
vector<int> graph[200001], ans;
unordered_map<int, bool> potion, visited;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>k;
        for(int j=0; j<k; j++) cin>>x[j];
        cin>>r;
        for(int j=1; j<=k; j++){
            graph[x[j]].push_back(r);
            indgree[r]++;
        }
    }
    cin>>l;
    for(int i=0; i<l; i++){
        cin>>y;
        potion[y]=1;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indgree[i]==0 && potion[i]) q.push(i);
    }

    while(!q.empty()){
        int node=q.front(); q.pop();
        if(visited[node]) continue;
        visited[node]=1;
        if(indgree[node]==0) ans.push_back(node);
        for(auto g:graph[node]){
            if(--indgree[g]==0) q.push(g);
        }
    }

    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    cout<<"\n";
}