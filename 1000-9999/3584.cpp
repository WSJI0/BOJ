//3584번 가장 가까운 공통 조상

#include <bits/stdc++.h>
using namespace std;

int parent[10001];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, a, b, t1, t2;
    cin>>t;
    while(t--){
        for(int i=0; i<10001; i++) parent[i]=0;
        cin>>n; n--;
        while(n--){
            cin>>a>>b;
            parent[b]=a;
        }
        cin>>t1>>t2;

        set<int> visited;
        queue<int> q;
        q.push(t1); q.push(t2);
        
        while(!q.empty()){
            int node=q.front(); q.pop();
            if(visited.find(node)==visited.end()){
                visited.insert(node);
                if(parent[node]){
                    q.push(parent[node]);
                }
            }
            else{
                cout<<node<<"\n";
                break;
            }
        }
    }
}