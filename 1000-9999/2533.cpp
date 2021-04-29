// 2533번 사회망 서비스(SNS)

#include <bits/stdc++.h>
using namespace std;

int n, u, v, root, ans1, ans2;
vector<int> graph[1000001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    cin>>u>>v;
    root=u;
    graph[u].push_back(v);
    for(int i=0; i<n-2; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        if(root==v) root=u;
    }

    queue<int> q;
    q.push(root);
    
    int cnt=0;
    while(!q.empty()){
        int qs=q.size();
        while(qs--){
            if(cnt%2==0) ans1++;
            else ans2++;
            int node=q.front(); q.pop();
            for(int i:graph[node])
                q.push(i);
        }
        cnt++;
    }

    cout<<min(ans1, ans2)<<"\n";
}