#include <bits/stdc++.h>
using namespace std;

int T, n, t[501], m, a, b;
int graph[501][501];
int indgree[501];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>T;
    while(T--){
        memset(graph, 0, sizeof(graph));
        memset(indgree, 0, sizeof(indgree));

        cin>>n;
        for(int i=0; i<n; i++) cin>>t[i];
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                graph[t[j]][t[i]]=1;
                indgree[t[i]]++;
            }
        }

        cin>>m;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            if(graph[b][a]){
                indgree[a]--;
                indgree[b]++;
                graph[b][a]=0;
                graph[a][b]=1;
            } else{
                indgree[b]--;
                indgree[a]++;
                graph[a][b]=0;
                graph[b][a]=1;
            }
        }

        queue<int> q;
        for(int i=1; i<=n; i++){
            if(--indgree[i]==0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node=q.front(); q.pop();
            ans.push_back(node);
            for(int g=1; g<=n; g++){
                if(!graph[node][g]) continue;
                if(--indgree[g]==0){
                    q.push(g);
                }
            }
        } 

        if(ans.size()!=n) cout<<"IMPOSSIBLE"<<"\n";
        else {
            for(int i=n-1; i>=0; i--) cout<<ans[i]<<" ";
            cout<<"\n";
        }
    }
}