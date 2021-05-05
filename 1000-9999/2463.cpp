// 2463번 비용

#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, w, parent[100001];

void merge(int u, int v){
    if(u==v) return;
    
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<=100000; i++) parent[i]=i;

    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>x>>y>>w;
        merge(x, y);
    }
}