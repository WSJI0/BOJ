//14466번 소가 길을 건너간 이유 6

#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, vector<pair<int, int>>> graph;
int bfs(pair<int, int> cow1, pair<int, int> cow2){
    queue<pair<int, int>> q;
    bool visited[101][101]={0};
    q.push(cow1);
    visited[q.front().first][q.front().second]=1;
    while(!q.empty()){
        pair<int, int> node=q.front(); q.pop();
        if(node==cow2) return 0;
        for(auto g:graph[node]){
            if(!visited[g.first][g.second]){
                visited[g.first][g.second]=1;
                q.push(g);
            }
        }
    }
    return 1;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, r;
    cin>>n>>k>>r;
    for(int i=0; i<r; i++){
        int r1, r2, c1, c2;
        cin>>r1>>c1>>r2>>c2;
        pair<int, int> p1(r1, c1);
        pair<int, int> p2(r2, c2);
        graph[p1].push_back(p2);
        graph[p2].push_back(p1);
    }
    vector<pair<int, int>> cow;
    for(int i=0; i<k; i++){
        int cowX, cowY;
        cin>>cowX>>cowY;
        cow.push_back(make_pair(cowX, cowY));
    }

    int ans=0;
    for(int i=0; i<k; i++){
        for(int j=i+1; j<k; j++){
            ans+=bfs(cow[i], cow[j]);
        }
    }
    cout<<ans<<"\n";
}