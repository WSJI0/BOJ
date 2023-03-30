#include <bits/stdc++.h>
using namespace std;

int n, sq[4];
int parent[1002*1000+1005];
bool vis[1002*1000+1005];
int level[1002*1000+1005]={1, };

int c(int y, int x){
    return y*1002+x;
}

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
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for(int i=0; i<=1002*1000+1000; i++) parent[i]=i;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>sq[0]>>sq[1]>>sq[2]>>sq[3];
        for(int j=0; j<4; j++) sq[j]+=500;

        for(int j=sq[0]; j<=sq[2]; j++){
            merge(c(sq[0], sq[1]), c(j, sq[1]));
            merge(c(sq[0], sq[1]), c(j, sq[3]));
        }
        for(int j=sq[1]; j<=sq[3]; j++){
            merge(c(sq[0], sq[1]), c(sq[0], j));
            merge(c(sq[0], sq[1]), c(sq[2], j));
        }
    }

    int ans=0;
    for(int i=0; i<=1000; i++){
        for(int j=0; j<=1000; j++){
            if(find(c(i, j))==c(i, j)) continue;
            if(find(c(500, 500))!=find(c(i, j))){
                if(vis[find(c(i, j))]) continue;
                vis[find(c(i, j))]=1;
                ans++;
            }
        } 
    }

    cout<<ans<<"\n";
}