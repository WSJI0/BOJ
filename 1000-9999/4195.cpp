//4195번 친구 네트워크

#include <bits/stdc++.h>
using namespace std;

int parent[200001];
int res[200001];
int find(int u){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
}

int merge(int u, int v){
    u=find(u); v=find(v);
    if(u!=v){
        parent[u]=v;
        res[v]+=res[u];
        res[u]=1;
    }
    return res[v];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin>>t;
    while(t--){
        int num=1;
        string A, B;
        map<string, int> name;
        cin>>n;
        for(int i=0; i<=n*2; i++){
            parent[i]=i;
            res[i]=1;
        }
        while(n--){
            cin>>A>>B;
            if(name[A]==0) name[A]=num++;
            if(name[B]==0) name[B]=num++;
            cout<<merge(name[A], name[B])<<"\n";
        }
    }
}