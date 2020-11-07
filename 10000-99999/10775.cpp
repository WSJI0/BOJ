//10775번 공항

#include <bits/stdc++.h>
using namespace std;

int parent[100001];

int find(int u){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
}
void merge(int u, int v){
    u=find(u); v=find(v);
    if(u==v) return;
    parent[u]=v;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i=0; i<100001; i++) parent[i]=i;

    int G, P, ans=0, g, in=1;
    cin>>G>>P;
    for(int i=0; i<P; i++){
        cin>>g;
        if(in){
            if(find(g)!=0){
                ans++;
                merge(find(g), find(g)-1);
            } else in=0;
        }
    }
    cout<<ans<<"\n";
}