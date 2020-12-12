// 3665번 최종 순위

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, m, a, b, tmp;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> indgree(n);
        vector<int> graph[501];
        for(int i=0; i<=n; i++) graph[i].clear();

        cin>>tmp;
        for(int i=0; i<n-1; i++){
            cin>>a;
            indgree[tmp]++;
            graph[tmp].push_back(a);
            tmp=a;
        }

        cin>>m;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            
        }

        queue<int> q;
        for(int i=1; i<=n; i++){
            if(indgree[i]==0) q.push(i);
        }
        
    }
}