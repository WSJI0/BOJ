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
    if(u>v) parent[u]=v;
    else parent[v]=u;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin>>t;
    while(t--){
        int num=1;
        string A, B;
        map<string, int> name;
        vector<int> F(100001);
        cin>>n;
        while(n--){
            cin>>A>>B;
            if(name[A]==0) name[A]=num++;
            if(name[B]==0) name[B]=num++;
            merge(name[A], name[B]);
            
        }
    }
}