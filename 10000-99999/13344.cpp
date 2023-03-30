#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
char k;
int parent[50001], level[50001];
int qq[250001][2], indgree[50001];
vector<int> graph[50001];
bool vis[50001];

int find(int u){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
}

void merge(int u, int v){
    u=find(u); v=find(v);
    if(u==v) return;
    if(level[u]>level[v]){
        parent[v]=u;
        level[u]+=level[v];
    } else{
        parent[u]=v;
        level[v]+=level[u];
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<=50000; i++){
        parent[i]=i;
        level[i]=1;
    }
    int qc=0;

    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>k>>b;
        if(k=='='){
            merge(a, b);
        } else if(k=='>'){
            qq[qc][0]=a;
            qq[qc][1]=b;
            qc++;
        } else if(k=='<'){
            qq[qc][0]=b;
            qq[qc][1]=a;
            qc++;
        }
    }

    queue<int> q;
    for(int i=0; i<qc; i++){
        int a=qq[i][0];
        int b=qq[i][1];
        if(find(a)==find(b)){
            cout<<"inconsistent"<<"\n";
            return 0;
        }
        graph[find(b)].push_back(find(a));
        indgree[find(a)]++;
    }

    for(int i=0; i<=n; i++){
        int f=find(i);
        if(indgree[f]==0){
            if(vis[f]) continue;
            vis[f]=1;
            q.push(f);
        }
    }

    for(int i=0; i<=n; i++) cout<<find(i)<<" ";
    cout<<"\n";
    for(int i=0; i<=n; i++) cout<<indgree[find(i)]<<" ";
    cout<<"\n";
    for(int i=0; i<=n; i++) cout<<level[find(i)]<<" ";
    cout<<"\n";

    int cnt=0;
    while(!q.empty()){
        int node=q.front(); q.pop();
        cnt+=level[node];
        for(auto g:graph[node]){
            indgree[g]-=level[g];
            if(indgree[g]==0) q.push(g);
        }
    }

    cout<<cnt<<"\n";
    if(cnt==n+1) cout<<"consistent"<<"\n";
    else cout<<"inconsistent"<<"\n";
}