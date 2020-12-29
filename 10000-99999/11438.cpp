// 11438 LCA 2

#include <bits/stdc++.h>
using namespace std;

int depth[100001], ac[100001][21];
vector<int> graph[100001];

void getTree(int cur, int parent){
    depth[cur]=depth[parent]+1;
    ac[cur][0]=parent;

    for(int i=1; i<=20; i++){
        ac[cur][i]=ac[ac[cur][i-1]][i-1];
    }
    for(int i=0; i<graph[cur].size(); i++){
        int nxt=graph[cur][i];
        if(nxt==parent) continue;
        getTree(nxt, cur);
    }   
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b;
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    depth[0]=-1;
    getTree(1, 0);

    cin>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        if(depth[a]!=depth[b]){
            if(depth[a]>depth[b]) swap(a, b);
            for(int j=20; j>=0; j--){
                if(depth[a]<=depth[ac[b][j]]) b=ac[b][j];
            }
        }
        int ans=a;
        if(a!=b){
            for(int j=20; j>=0; j--){
                if(ac[a][j]!=ac[b][j]){
                    a=ac[a][j];
                    b=ac[b][j];
                }
                ans=ac[a][j];
            }
        }
        cout<<ans<<"\n";
    }
}
