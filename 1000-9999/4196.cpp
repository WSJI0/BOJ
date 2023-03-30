//4196번 도미노

#include <bits/stdc++.h>
using namespace std;

int t, n, m, u, v, id;
vector<int> graph[100001];
int visited[100001];
bool fin[100001];
stack<int> s;

int solve(int cur){
    int p=visited[cur]=++id;
    s.push(cur);

    for(auto g:graph[cur]){
        if(visited[g]==0) p=min(p, solve(g));
        else if(!fin[g]) p=min(p, visited[g]);
    }

    if(p==visited[cur]){
        int t=-1;
        while(t!=cur){
            t=s.top(); s.pop();
            fin[t]=1;
        }
    }
    return p;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>t;
    while(t--){
        for(int i=0; i<=100000; i++){
            graph[i].clear();
            visited[i]=0;
        } id=0;

        cin>>n>>m;
        for(int i=0; i<n; i++){
            cin>>u>>v;
            graph[u].push_back(v);
        }

        int ans=0;
        for(int i=1; i<=n; i++){
            if(visited[i]==0){
                solve(i);
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}