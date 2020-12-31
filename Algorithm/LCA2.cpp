//LCA(최소 공통조상)의 다른 구현

#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
int parent[100001][20];
int depth[100001];
vector<int> graph[100001];

void dfs(int cur){
    for(auto nxt:graph[cur]){
        if(depth[nxt]!=-1) continue;
        parent[nxt][0]=cur;
        depth[nxt]=depth[cur]+1;
        dfs(nxt);
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}