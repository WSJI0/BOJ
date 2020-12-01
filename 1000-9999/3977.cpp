//3977번 축구 전술

#include <bits/stdc++.h>
using namespace std;

int v, e, a, b, vis[100001], id=0;
bool fin[100001];
vector<int> graph[100001];
vector<int> scc;
stack<int> s;

int dfs(int x){
    vis[x]=++id;
    s.push(x);
    int parent=vis[x];
    for(auto y:graph[x]){
        if(vis[y]==0) parent=min(parent, dfs(y));
        else if(!fin[y]) parent=min(parent, vis[y]);
    }
    if(parent==vis[x]){
        int cnt=0;
        while(1){
            cnt++;
            int t=s.top(); s.pop();
            scc.push_back(t);
            fin[t]=1;
            if(t==x) break;
        }
        if(cnt==1) scc.pop_back();
    }
    return parent;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>v>>e;

        scc.clear();
        for(int i=0; i<100000; i++){
            graph[i].clear();
            vis[i]=fin[i]=0;
        }

        for(int i=0; i<e; i++){
            cin>>a>>b;
            graph[a].push_back(b);
            if(a==b) scc.push_back(a);
        }
        for(int i=0; i<v; i++) 
            if(vis[i]==0) dfs(i);
        
        if(scc.size()==0){
            cout<<"Confused"<<"\n\n";
            continue;
        }
        sort(scc.begin(), scc.end());
        for(int i=0; i<scc.size(); i++){
            cout<<scc[i]<<"\n";
        } cout<<"\n";
    }
}