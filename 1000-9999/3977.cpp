#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b, id, sid=1;
vector<int> graph[100001];
int dp[100001], sc[100001], no[100001];
bool vis[100001];
stack<int> s;

int scc(int cur){
    int p=dp[cur]=++id;
    s.push(cur);

    for(auto g:graph[cur]){
        if(dp[g] && !vis[g]) p=min(p, dp[g]);
        else if(!dp[g]) p=min(p, scc(g));
    }
    if(p==dp[cur]){
        int t=-1;
        while(t!=cur){
            t=s.top(); s.pop();
            vis[t]=1;
            sc[t]=sid;
        } sid++;
    }
    return p;
}

void solve(int cur){
    for(auto g:graph[cur]){
        if(sc[g]!=sc[cur]){
            if(no[sc[cur]]!=0 && no[sc[cur]]!=sc[g]) sid=-1;
            no[sc[cur]]=sc[g];
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>t;
    while(t--){
        // for(int i=0; i<=100000; i++) graph[i].clear();
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));

        cin>>n>>m;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            graph[b].push_back(a);
        }
        
        for(int i=0; i<n; i++){
            if(!vis[i]) scc(i);
        } 
        memset(vis, 0, sizeof(vis));

        for(int i=0; i<n; i++) solve(i);
        if(sid==-1){
            cout<<"Confused"<<"\n\n";
            continue;
        }

        vector<int> res;
        for(int i=1; i<sid; i++){
            if(!no[i]) res.push_back(i);
        }
        for(int i=0; i<n; i++){
            for(int j:res){
                if(sc[i]==j) cout<<i<<"\n";
            }
        } cout<<"\n";
    }
}