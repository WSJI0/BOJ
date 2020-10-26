#include <bits/stdc++.h>
using namespace std;

stack<int> s;
map<int, int> ans;
vector<vector<int>> graph(1001);
void dfs(int n){
    bool res=false;
    for(auto i:graph[n]){
        if(ans[i]==0) res=true;
    }
    if(graph[n].empty() || !res){
        ans[n]=1;
        s.push(n);
        return;
    }
    for(auto i:graph[n])
        if(ans[i]!=1) dfs(i);
}

void CLEAR(stack<int> &s){
    for(int i=0; i<s.size(); i++) s.pop();
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, k, x, y, w;
    cin>>t;
    while(t--){
        ans.clear(); graph.clear(); CLEAR(s);
        cin>>n>>k;
        vector<int> D(n+1);
        for(int i=1; i<=n; i++) cin>>D[i];
        for(int i=0; i<k; i++){
            cin>>x>>y;
            graph[x].push_back(y);
        }
        for(int i=1; i<=n; i++)
            if(ans[i]==0) dfs(i);
        cin>>w;
        int bT=0;
        cout<<"ANS : ";
        for(int i=0; i<s.size(); i++){
            cout<<s.top()<<" ";
            s.pop();
        }cout<<endl;
/*
        for(int i=0; i<s.size(); i++){
            bT+=D[s.top()];
            if(s.top()==w) break;
            s.pop();
        }
        cout<<bT<<endl;*/
    }
}